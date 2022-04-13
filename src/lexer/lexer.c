/*
 * find out if the array of tokens is invalid
 * go through the linked list of pipes and see if it is alowed
 */

/*
 *
 */

 #include "minishell.h"

/*
 *	int		tk_lexer(t_list *tokens);
 *	return value is NULL on succes
 *	and 1 on succes
 *	error message is written inside this function
 */

// na > (of andere redirection) altijd een string		>> < << heredoc
// na | altijd niet een pipe
// na string mag alles
// anders error
// //mag niet beginnen met een pipe





int	lx_error(char *token)
{
	write(2, "syntax error near unexpected token `", ft_strlen("syntax error near unexpected token `"));
	write(2, token, ft_strlen(token));
	write(2, "'\n", 2);
	return (0);
}


// typedef struct	s_pipe
// {
// 	bool	pipe_before;
// 	bool	pipe_after;
// 	int		input_fd;
// 	int		output_fd;
// 	// char	*input_fn;
// 	// char	*output_fn;
// 	// char	*append_fn;
// 	// char	*heredoc_fn;
// 	char	**tokens;
// 	int		pipe_fd[2];
// }				t_pipe;


int	ms_parser(t_list **tokens, t_mini *mini)
{
	t_list *pipes;
	int		i;
	int		c;
	int		a;
	char	**new;
	
	i = 0;
	a = 0;
	c = 0;
	pipes = 0;
	mini->pipe_before = 0;
	mini->pipe_after = 0;
	mini->tokenarr = malloc(sizeof(char *) * (1 + 1));
	if (mini->pipes > 0)
		mini->pipe_after = 1;
	new = get_args_exec((*tokens));
	if (!new)
		ft_disruptive_exit("malloc fail", 333);
	while (new[c])
	{
		mini->tokenarr[a] = ft_strdup(new[c]);
		if (!mini->tokenarr[a])
			ft_disruptive_exit("malloc fail", 333);
		a++;
		c++;
	}
	mini->tokenarr[a] = NULL;
	ms_lstadd_pipe(&pipes, mini);
	// char	**new;
	// ft_print2darr(new);
	while ((*tokens) && (*tokens)->next)
	{
		if (((t_token *)(*tokens)->content)->id == Pipe)
		{
			i++;
			if (mini->pipes - i > 0)
				mini->pipe_after = 1;
			mini->pipe_before = 1;
			new = get_args_exec((*tokens));
			if (!new)
				ft_disruptive_exit("malloc fail", 333);
			a = 0;
			c = 0;
			// while (mini->tokenarr[a])
			// {
			// 	free(mini->tokenarr[a]);
			// 	a++;
			// }
			while (new[c])
			{
				mini->tokenarr[a] = ft_strdup(new[c]);
				if (!mini->tokenarr[a])
					ft_disruptive_exit("malloc fail", 333);
				a++;
				c++;
			}
			mini->tokenarr[a] = NULL;
			ms_lstadd_pipe(&pipes, mini);
			// ft_print2darr(new);
		}
		mini->pipe_after = 0;
		(*tokens) = (*tokens)->next;
	}
	ft_printpipes(pipes);
	return (0);
}

void	ms_count(t_list *tokens, t_mini *mini)
{
	mini->pipes = 0;
	mini->tokens = 1;
	while (tokens && tokens->next)
	{
		if (((t_token *)tokens->content)->id == Pipe)
			mini->pipes++;
		mini->tokens++;
		tokens = tokens->next;
	}
	// printf ("%d\n", mini->pipes);
}

int	ms_lexer(t_list *tokens)
{
	// ft_printtokens(tokens);
	if (((t_token *)tokens->content)->id == Pipe)
		return(lx_error("|"));
	while (tokens && tokens->next)
	{
		if (((t_token *)tokens->content)->id == Heredoc && ((t_token *)tokens->next->content)->id != Str)
			return(lx_error("<<"));
		if (((t_token *)tokens->content)->id == Write && ((t_token *)tokens->next->content)->id != Str)
			return(lx_error(">"));
		if (((t_token *)tokens->content)->id == Read && ((t_token *)tokens->next->content)->id != Str)
			return(lx_error("<"));
		if (((t_token *)tokens->content)->id == Append && ((t_token *)tokens->next->content)->id != Str)
			return(lx_error(">>"));
		if (((t_token *)tokens->content)->id == Pipe && ((t_token *)tokens->next->content)->id == Pipe)
			return(lx_error("|"));
		tokens = tokens->next;
	}
	if (((t_token *)tokens->content)->id != Str)
		return(lx_error("newline"));
	return (1);
}
