#include "minishell.h"

int		count_words(t_list *tokens)
{
	int	words;

	words = 0;
	if (((t_token *)tokens->content)->id == Pipe)
		tokens = tokens->next;
	while (tokens)
	{
		if (((t_token *)tokens->content)->id == Pipe)
			break ;
		words++;
		tokens = tokens->next;
	}
	return (words);
}

char	**get_args_exec(t_list *tokens)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * (count_words(tokens) + 1));
	if (((t_token *)tokens->content)->id == Pipe)
		tokens = tokens->next;
	while (tokens)
	{
		if (((t_token *)tokens->content)->id == Pipe)
			break ;
		// if (((t_token *)tokens->content)->id == Heredoc || ((t_token *)tokens->content)->id == Write || ((t_token *)tokens->content)->id == Read || ((t_token *)tokens->content)->id == Append)
		// {
		// 	tokens = tokens->next;
		// 	if (tokens->next)
		// 		tokens = tokens->next;
		// }
		new[i] = ft_strdup(((t_token *)tokens->content)->word);
		if (!new[i])
			ft_disruptive_exit("malloc fail", 333);
		tokens = tokens->next;
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	parser_init(t_pipe *pipe, t_mini *mini, char **tokenarr)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	(void)mini;
	// pipe->pipe_before = mini->pipe_before;
	// pipe->pipe_after = mini->pipe_after;
	pipe->tokens = tokenarr;
	pipe->output_fd = STDOUT_FILENO;
	pipe->input_fd = STDIN_FILENO;

}

int	ms_lstadd_pipe(t_list **pipes, t_mini *mini, char **tokenarr)
{
	t_list	*new;
	t_pipe	*pipe;

	pipe = malloc(sizeof(t_pipe));
	if (pipe == NULL)
		ft_disruptive_exit("malloc fail", 333);
	parser_init(pipe, mini, tokenarr);
	new = ft_lstnew((void *)pipe);
	if (new == NULL)
	{
		free(pipe);
		ft_disruptive_exit("malloc fail", 333);
	}
	ft_lstadd_back(pipes, new);
	return (0);
}

t_list	*ms_parser(t_list **tokens, t_mini *mini)
{
	t_list *pipes;
	int     i;
	char    **new;
	
	i = 0;
	pipes = 0;
	// mini->pipe_before = 0;
	// mini->pipe_after = 0;
	// if (mini->pipes > 0)
	// 	mini->pipe_after = 1;
	new = get_args_exec((*tokens));
	if (!new)
		ft_disruptive_exit("malloc fail", 333);
	ms_lstadd_pipe(&pipes, mini, new);
	// printf("pipes%d\n", mini->pipe_after);
	// find_redirects(new, mini);
	while ((*tokens) && (*tokens)->next)
	{
		if (((t_token *)(*tokens)->content)->id == Pipe)
		{
			i++;
			// if (mini->pipes - i > 0)
			// 	mini->pipe_after = 1;
			// mini->pipe_before = 1;
			new = get_args_exec((*tokens));
			if (!new)
				ft_disruptive_exit("malloc fail", 333);
			// find_redirects(new, mini);
			ms_lstadd_pipe(&pipes, mini, new);
		}
		// mini->pipe_after = 0;
		(*tokens) = (*tokens)->next;
	}
	return (pipes);
}

// void	ms_count(t_list *tokens, t_mini *mini)
// {
// 	mini->pipes = 0;
// 	// mini->tokens = 1;
// 	while (tokens && tokens->next)
// 	{
// 		if (((t_token *)tokens->content)->id == Pipe)
// 			mini->pipes++;
// 		// mini->tokens++;
// 		tokens = tokens->next;
// 	}
// }
