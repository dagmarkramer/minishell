#include "tokenizer.h"

// ft_lstclear(tokens, ms_del_token);
void	ms_del_token(void *incomming)
{
	t_token	*token;

	token = (t_token *)incomming;
	free(token->word);
	free(token);
}

int	ms_lstadd_token(t_list **tokens, char *word)
{
	t_list	*new;
	t_token	*n_token;

	if (word == NULL)
		return (1);
	n_token = malloc(sizeof(t_token));
	if (n_token == NULL)
		return (1);
	n_token->word = word;
	new = ft_lstnew((void *)n_token);
	if (new == NULL)
	{
		free(word);
		free(n_token);
		return (1);
	}
	ft_lstadd_back(tokens, new);
	return (0);
}

int	ms_find_offset(char *in, char *delimiters, int offset)
{
	int	i;

	i = offset;
	while (in[i])
	{
		if (ft_strchr(delimiters, in[i]))
			return (i);
		i++;
	}
	return (i);
}

int	ms_skip_chars(char *in, char *to_skip, int offset)
{
	int	i;

	i = offset;
	while (ft_strchr(to_skip, in[i]))
	{
		i++;
	}
	return (i);
}
