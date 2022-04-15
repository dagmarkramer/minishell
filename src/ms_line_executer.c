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
	t_list	*pipes;

	data->input = tk_expander(data->input, data->env);
	tokens = ms_tokenizer(data->input, data->env);
	if (tokens == NULL)
		return ;
	// tk_expand_all(tokens, data->env);
	ft_lstiter(tokens, tk_remove_quotes);
	ft_lstiter(tokens, ms_print_word);
	
	if (ms_lexer(tokens) == 0)
	{
		ft_lstclear(&tokens, ms_del_token);
		return ;
	}
	ms_count(tokens, data);
	// if (data->pipes == 0)
	// 	ex_nopipes();
	pipes = ms_parser(&tokens, data);
	// go to execution
	// free everything in the linked token list
	ft_lstclear(&tokens, ms_del_token);
}
