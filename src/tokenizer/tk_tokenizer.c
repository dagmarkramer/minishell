/*
 * This function is used to call all the subroutines needed
 * to tokenize and prepare the tokenized words further before executing.
 * 
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
	tk_name_tokens(tokens);
	// tk_expand_all(tokens, env);
	ft_lstiter(tokens, tk_remove_quotes);
	//lexer?		is this a correct combo of tokens or do I give an error?
	return (tokens);
}
