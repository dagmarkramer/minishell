/*
 *	This function turns the input string into tokens
 *	it uses the same rules as bash for splitting up words but
 *	changes closes quotes instead of giving a newline when quotes are unclused at the end
 */


#include "tokenizer.h"

t_list	*ms_tokenizer(char *input, t_list *env)
{
	t_list	*tokens;

	(void)env;

	tokens = 0;
	if (ms_add_tokens(&tokens, input))
	{
		ft_lstclear(&tokens, ms_del_token);
		return (NULL);
	}
	ft_lstiter(tokens, tk_name_token);
	return (tokens);
}
