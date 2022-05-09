/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_line_executer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:45:09 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/09 22:45:10 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exe_pipe_and_run(t_list *pipes, t_mini *data)
{
	int	pipefd[2];
	int	errorcode;

	if (pipes->next == NULL
		&& is_buildin(((t_pipe *)pipes->content)->tokens[0]))
		return (exe_pre_buildin((t_pipe *)pipes->content, data));
	while (pipes->next != NULL)
	{
		if (pipe(pipefd) == -1)
			ft_disruptive_exit("pipe failed", 42);
		((t_pipe *)pipes->content)->output_fd = pipefd[1];
		((t_pipe *)pipes->next->content)->input_fd = pipefd[0];
		errorcode = exe_pre_fork((t_pipe *)pipes->content, data);
		if (errorcode)
			return (errorcode);
		pipes = pipes->next;
	}
	return (exe_pre_fork((t_pipe *)pipes->content, data));
}

void	fillnewinput(t_mini *data, char *exitstatus, char **newinput)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (data->input[i])
	{
		if (data->input[i] == '$' && data->input[i + 1] == '?')
		{
			while (*exitstatus)
			{
				(*newinput)[a] = *exitstatus;
				a++;
				exitstatus++;
			}
			i += 2;
		}
		(*newinput)[a] = data->input[i];
		if ((*newinput)[a])
			a++;
		if (data->input[i])
			i++;
	}
	(*newinput)[a] = '\0';
}

void	replaceexitstatus(t_mini *data)
{
	char	*newinput;
	char	*exitstatus;

	exitstatus = ft_itoa(data->last_return);
	ft_malloc_fail_check(exitstatus);
	newinput = malloc(sizeof(char) * (ft_strlen(data->input) - 2
				+ ft_strlen(exitstatus) + 1));
	ft_malloc_fail_check(newinput);
	fillnewinput(data, exitstatus, &newinput);
	free (data->input);
	free (exitstatus);
	data->input = newinput;
}

void	wildcards_expander(t_list **tokens);

void	ms_line_executer(t_mini *data)
{
	t_list	*tokens;
	t_list	*pipes;

	if (ft_strnstr(data->input, "$?", ft_strlen(data->input)))
		replaceexitstatus(data);
	data->input = tk_expander(data->input, data->env);
	tokens = ms_tokenizer(data->input);
	if (!tokens)
		ft_disruptive_exit("malloc fail", 333);
	free(data->input);
	if (tokens == NULL)
		return ;
	ft_lstiter(tokens, tk_remove_quotes);
	wildcards_expander(&tokens);
	if (ms_lexer(tokens) == 0)
	{
		ft_lstclear(&tokens, ms_del_token);
		return ;
	}
	pipes = ms_parser(&tokens);
	ft_lstclear(&tokens, ms_del_token);
	data->last_return = exe_pipe_and_run(pipes, data);
	ft_lstclear(&pipes, NULL);
}
