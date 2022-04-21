 #include "minishell.h"

/*
 *	int		tk_lexer(t_list *tokens);
 *	return value is ZERO on succes
 *	and 1 on succes
 *	error message is written inside this function
 */

int	lx_error(char *token)
{
	write(2, "syntax error near unexpected token `", ft_strlen("syntax error near unexpected token `"));
	write(2, token, ft_strlen(token));
	write(2, "'\n", 2);
	return (0);
}

int	ms_lexer(t_list *tokens)
{
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
