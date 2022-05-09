/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:48:13 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/09 22:48:14 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printlst(t_list *lst, char *env)
{
	while (lst)
	{
		if (!ft_strncmp("export", env, 1 + ft_strlen("export")))
		{
			printf("declare -x ");
			printf("%s=\"", (char *)((t_keyval *)lst->content)->key);
			printf("%s\"\n", (char *)((t_keyval *)lst->content)->value);
		}
		if (!ft_strncmp("env", env, 1 + ft_strlen("env")))
		{
			printf("%s=", (char *)((t_keyval *)lst->content)->key);
			printf("%s\n", (char *)((t_keyval *)lst->content)->value);
		}
		lst = lst->next;
	}
}
