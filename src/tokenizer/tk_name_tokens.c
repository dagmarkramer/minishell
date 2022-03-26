#include "tokenizer.h"

void	tk_name_token(void *in)
{
	t_token		*token;
	char		*word;

	token = (t_token *)in;
	word = token->word;
	if (word[0] == '|')
		token->id = Pipe;
	else if (word[0] == '<' && word[1] == '<')
		token->id = Heredoc;
	else if (word[0] == '<' || word[0] == '>')
		token->id = Redirection;
	else
		token->id = Str;
}

void	tk_name_tokens(t_list *tokens)
{
	ft_lstiter(tokens, tk_name_token);
}
