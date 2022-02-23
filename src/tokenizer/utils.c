#include "minishell.h"

typedef struct	s_token
{
	int		token_id;
	char	form;
	char	**word;
}				t_token;

// ft_lstclear(tokens, ms_del_token);
void	ms_del_token(void *incomming)
{
	t_token	*token;
	int		i;

	i = 0;
	token = (t_token *)incomming;
	while (token->word[i])
	{
		free(token->word[i]);
		i++;
	}
	free(token);
}

int	ms_add_token(t_list *tokens, char **word)
{
	t_list	new;

	new = ft_lstnew((void *)word);
	if (new == NULL)
		return (505);
	ft_lstadd_back(tokens, new);
	return (0);
}
