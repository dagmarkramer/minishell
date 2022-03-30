#include "minishell.h"

int		ev_add_env(char *key, char *value, t_list **envlst)
{
	t_list	*new;

	new = ev_keyval_lst_add(key, value);
	if (new == NULL)
		return (1); // error
	ft_lstadd_back(envlst, new);
	ev_sort_alfa(*envlst);
	return (0);
}

int		ev_rem_env(char *key, char *value, t_list **envlst)
{
	// t_list	*new;

	// new = ev_keyval_lst_add(key, value);
	// if (new == NULL)
	// 	return (1); // error
	// ft_lstadd_back(envlst, new);
	// ev_sort_alfa(*envlst);
	while (*envlst)
	{
		if (!ft_strncmp((char *)((t_keyval *)envlst->content)->key), key, ft_strlen((char *)((t_keyval *)envlst->content)->key)))
			ev_del_keyval(envlst->content);
		*envlst = *envlst->next;
	}

	return (0);
}