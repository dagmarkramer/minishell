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

int		ev_rem_env(char *key, t_list **env)
{
	// t_list	*prev;
	// t_list	*envlst;

	// envlst = *env;
	// // new = ev_keyval_lst_add(key, value);
	// // if (new == NULL)
	// // 	return (1); // error
	// // ft_lstadd_back(envlst, new);
	// // ev_sort_alfa(*envlst);
	// prev = 0;
	// while (envlst)
	// {
	// 	printf("%d\n", ft_strncmp((char *)((t_keyval *)envlst->content)->key, key, ft_strlen((char *)((t_keyval *)envlst->content)->key)));
	// 	if (!ft_strncmp((char *)((t_keyval *)envlst->content)->key, key, ft_strlen((char *)((t_keyval *)envlst->content)->key)))
	// 	{
	// 		if (!prev)
	// 			*env = envlst->next;
	// 		else
	// 			prev->next = envlst->next;
	// 		// (envlst)->next = (envlst)->next->next;
	// 		ev_del_keyval(envlst->content);
	// 		free(envlst);
	// 	}
	// 	prev = envlst;
	// 	envlst = envlst->next;
	// }
	t_list	*tmp;
	while (env && *env)
	{
		if (!ft_strncmp((char *)((t_keyval *)(*env)->content)->key, key, ft_strlen((char *)((t_keyval *)(*env)->content)->key)))
		{
			tmp = (*env)->next;
			ev_del_keyval((*env)->content);
			free(*env);
			*env = tmp;
		}
		env = &((*env)->next);
		*env = (*env)->next;
	}

	return (0);
}