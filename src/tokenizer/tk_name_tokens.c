#include "tokenizer.h"

void	tk_name_token(void *in)
{
	t_token		*token;
	char		*word;

	token = (t_token *)in;
	word = token->word;
	if (word[0] == '|')
		token->id = Pipe;
	else if (word[0] == '<')
		token->id = Read;
	else if (word[0] == '>')
		token->id = Write;
	else
		token->id = Str;
}

void	tk_find_appends_and_heredoc(t_list *tokens)
{
	t_list	*tmp;
	while (tokens != NULL && tokens->next != NULL)
	{
		if (((t_token *)tokens->content)->word[0] == '<'
			&& ((t_token *)tokens->next->content)->word[0] == '<')
		{
			tmp = tokens->next;
			tokens->next = tokens->next->next;
			ms_del_token(tmp->content);
			free(tmp);
			((t_token *)tokens->content)->id = Heredoc;
		}
		else if (((t_token *)tokens->content)->word[0] == '>'
			&& ((t_token *)tokens->next->content)->word[0] == '>')
		{
			tmp = tokens->next;
			tokens->next = tokens->next->next;
			ms_del_token(tmp->content);
			free(tmp);
			((t_token *)tokens->content)->id = Append;
		}
		tokens = tokens->next;
	}
}

void	tk_name_tokens(t_list *tokens)
{
	ft_lstiter(tokens, tk_name_token);
	tk_find_appends_and_heredoc(tokens);
}
