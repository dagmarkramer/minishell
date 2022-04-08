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

int	ms_parser(t_list **tokens)
{
	t_list *pipes;
	bool	pipe_before;
	// bool	pipe_after;

	pipe_before = false;
	ms_lstadd_pipe(&pipes, pipe_before);
	while ((*tokens) && (*tokens)->next)
	{
		if (((t_token *)(*tokens)->content)->id == Pipe)
		{
			pipe_before = true;
			ms_lstadd_pipe(&pipes, pipe_before);
        	// printf("%d\n", (int)((t_pipe *)pipes->content)->pipe_before);
		}
		(*tokens) = (*tokens)->next;
	}
	// parser_init(&pipes);
	// ft_printpipes(pipes);
	return (0);
	return (7);
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
	return (0);
}