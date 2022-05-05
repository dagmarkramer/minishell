#include "libft.h"
#include "minishell.h"

char	**ft_lst_to_array(t_list *lst, void (*turn)(void *, char **))
{
	char	**array;
	int		lst_len;
	int		i;

	i = 0;
	lst_len = ft_lstsize(lst);
	array = malloc(sizeof(char *) * (lst_len + 1));
	if (array == NULL)
		return (NULL);
	array[lst_len] = 0;
	while (lst != NULL)
	{
		turn(lst->content, &array[i]);
		if (array[i] == NULL)
		{
			free_string_array(array);
			return (NULL);
		}
		lst = lst->next;
		i++;
	}
	return (array);
}

void	ev_turn_envlist(void *content, char **dst)
{
	t_dictionary	*current;
	char		*tmp;
	char		*product;

	current = (t_dictionary *)content;
	tmp = ft_stradd(current->key, "=");
	if (tmp == NULL)
	{
		*dst = NULL;
		return ;
	}
	product = ft_stradd(tmp, current->value);
	free(tmp);
	*dst = product;	
}
