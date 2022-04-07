#include "minishell.h"

void	ms_print_word(void *ptr)
{
	t_token	*token;

	token = (t_token *)ptr;
	printf("%s\n", token->word);
}

// void	go_execute(t_mini *data, t_list *tokens)
// {

// }

void	ms_line_executer(t_mini *data)
{
	t_list	*tokens;

	data->input = tk_expander(data->input, data->env);
	tokens = ms_tokenizer(data->input, data->env);
	if (tokens == NULL)
		return ;
	// tk_expand_all(tokens, data->env);
	ft_lstiter(tokens, tk_remove_quotes);
	ft_lstiter(tokens, ms_print_word);
<<<<<<< HEAD
	ms_lexer(tokens);
	ms_parser(&tokens);
=======

	// go_execute();
>>>>>>> e85e887a1108ad2053225f8e199952fad00ad542
	// go to execution
	// free everything in the linked token list
	ft_lstclear(&tokens, ms_del_token);
}
