/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ev_add_env.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:47:18 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/18 16:31:08 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	the functions in this file return 0 on succes and 1 on failure
 */

int	ev_add_env(char *key, char *value, t_list **envlst)
{
	t_list	*new;

	new = ev_keyval_lst_add(key, value);
	if (new == NULL)
		return (1);
	ft_lstadd_back(envlst, new);
	ev_sort_alfa(*envlst);
	return (0);
}

int	ev_rem_env(char *key, t_list **env)
{
	t_list	*tmp;

	while (env && *env)
	{
		if (!ft_strncmp((char *)((t_keyval *)(*env)->content)->key, key,
				1 + ft_strlen((char *)((t_keyval *)(*env)->content)->key)))
		{
			tmp = *env;
			*env = (*env)->next;
			ev_del_keyval(tmp->content);
			free(tmp);
			return (1);
		}
		env = &((*env)->next);
	}
	return (0);
}

int	ev_change_env(char *key, char *value, t_list **envlst)
{
	int	ret;

	ret = 0;

	if (ev_getenv(key, *envlst) && !value)
		return (0);
	ev_rem_env(key, envlst);
	ret = ev_add_env(key, value, envlst);
	return (ret);
}
