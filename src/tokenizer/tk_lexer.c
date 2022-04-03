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

int	lx_error(char *token)
{
	write(2, "syntax error near unexpected token `", ft_strlen("syntax error near unexpected token `"));
	write(2, token, ft_strlen(token));
	write(2, "'\n", 2);
}

int	tk_lexer(t_list *tokens)
{
	if (((t_token *)tokens->content)->id == Pipe)
		return(lx_error("|"));
	while (tokens && tokens->next)
	{

	}
}