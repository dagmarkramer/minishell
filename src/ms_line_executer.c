/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_line_executer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:45:09 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/14 15:33:00 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_pipe(void *content)
{
	t_pipe	*pipe;

	pipe = (t_pipe *)content;
	if (pipe->tokens != NULL)
		free_string_array(pipe->tokens);
	free(pipe);
}

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

void	ms_line_executer(t_mini *data)
{
	t_list	*tokens;
	t_list	*pipes;

	if (ft_strnstr(data->input, "$?", ft_strlen(data->input)))
		replaceexitstatus(data);
	data->input = tk_expander(data->input, data->env);
	tokens = ms_tokenizer(data->input);
	free(data->input);
	if (tokens == NULL)
		return ;
	ft_lstiter(tokens, tk_remove_quotes);
	wildcards_expander(&tokens);
	if (ms_lexer(tokens) != 0)
	{
		ft_lstclear(&tokens, ms_del_token);
		data->last_return = 258;
		return ;
	}
	pipes = ms_parser(&tokens);
	ft_lstclear(&tokens, ms_del_token);
	data->last_return = exe_pipe_and_run(pipes, data);
	ft_lstclear(&pipes, del_pipe);
}
