#include "tokenizer.h"

t_list	*ms_tokenizer(char *input, t_list *env)
{
	t_list	*tokens;

	tokens = 0;
	if (ms_add_tokens(&tokens, input))
	{
		ft_lstclear(&tokens, ms_del_token);
		return (NULL);
	}
	tk_name_tokens(tokens);
	tk_expand_all(tokens, env);
	//lexer?
	return (tokens);
}
