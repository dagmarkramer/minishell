#include "minishell"

t_list	*ms_tokenizer(char *input)
{
	t_list	*tokens;

	tokens = 0;
	if (ms_add_tokens(&tokens, input))
	{
		ft_lstclear(&tokens, ms_del_token);
		// ms_new_prompt(); or we can return NULL and catch that on function call
	}
	
	return (tokens);
}
