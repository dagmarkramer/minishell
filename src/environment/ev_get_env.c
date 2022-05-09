/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ev_get_env.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:47:24 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/09 22:47:24 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ev_getenv(char *key, t_list *envlst)
{
	t_keyval	*keyval;

	while (envlst != NULL)
	{
		keyval = (t_keyval *)envlst->content;
		if (ft_strncmp(key, keyval->key, 1 + ft_strlen(key)) == 0)
			return (keyval->value);
		envlst = envlst->next;
	}
	return (NULL);
}
