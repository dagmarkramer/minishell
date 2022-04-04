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
	else if (word[0] == '>' && word[1] == '>')
		token->id = Append;
	else if (word[0] == '<')
		token->id = Read;
	else if (word[0] == '>')
		token->id = Write;
	else
		token->id = Str;
}
