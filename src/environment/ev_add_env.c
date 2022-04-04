#include "minishell.h"

/*
 *	the functions in this file return 0 on succes and 1 on failure
 */

int		ev_add_env(char *key, char *value, t_list **envlst)
{
	t_list	*new;

	new = ev_keyval_lst_add(key, value);
	if (new == NULL)
		return (1);
	ft_lstadd_back(envlst, new);
	ev_sort_alfa(*envlst);
	return (0);
}

int		ev_rem_env(char *key, t_list **env)
{
	t_list	*tmp;
	while (env && *env)
	{
		if (!ft_strncmp((char *)((t_keyval *)(*env)->content)->key, key, ft_strlen((char *)((t_keyval *)(*env)->content)->key)))
		{
			tmp = *env;
			*env = (*env)->next;
			ev_del_keyval(tmp->content);
			free(tmp);
			return (0);
		}
		env = &((*env)->next);
	}
	return (1);
}
