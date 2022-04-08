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
	int	pipe_before;
	int pipe_after;
	// char	**tokenarr;
	int		i;
	// bool	pipe_after;
	i = 0;
	pipes = 0;
	pipe_before = 0;
	pipe_after = 0;
	printf ("%d\n", mini->pipes);
	if (mini->pipes > 0)
		pipe_after = 1;
	ms_lstadd_pipe(&pipes, pipe_before, pipe_after);
	char **str;
	str = token_list_to_array((*tokens), 10);
	printf("%s\n", str[0]);
	while ((*tokens) && (*tokens)->next)
	{
		// while (((t_token *)(*tokens)->content)->id != Pipe)
		// 	(*tokens) = (*tokens)->next;
		if (((t_token *)(*tokens)->content)->id == Pipe)
		{
			i++;
			if (mini->pipes - i > 0)
				pipe_after = 1;
			pipe_before = 1;
			// tokenarr = token_list_to_array((*tokens), int n)
			ms_lstadd_pipe(&pipes, pipe_before, pipe_after);
			
        	// printf("%d\n", (int)((t_pipe *)pipes->content)->pipe_before);
		}
		pipe_after = 0;
		(*tokens) = (*tokens)->next;
	}
	// parser_init(&pipes);
	ft_printpipes(pipes);
	return (0);
}

void	ms_countpipes(t_list *tokens, t_mini *mini)
{
	mini->pipes = 0;
	while (tokens && tokens->next)
	{
		if (((t_token *)tokens->content)->id == Pipe)
			mini->pipes++;
		tokens = tokens->next;
	}
	printf ("%d\n", mini->pipes);
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