/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:48:13 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/16 15:22:13 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isallnotalpha(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < 65 || (s[i] > 90 && s[i] < 97) || s[i] > 122)
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_printlst(t_list *lst, char *env)
{
	while (lst)
	{
		if (!ft_strncmp("export", env, 1 + ft_strlen("export")))
		{
			printf("declare -x ");
			printf("%s", (char *)((t_keyval *)lst->content)->key);
			if (((t_keyval *)lst->content)->value)
				printf("=\"%s\"\n", (char *)((t_keyval *)lst->content)->value);
			else
				printf("\n");
		}
		if (!ft_strncmp("env", env, 1 + ft_strlen("env")))
		{
			if (((t_keyval *)lst->content)->value)
			{
				printf("%s=", (char *)((t_keyval *)lst->content)->key);
				printf("%s\n", (char *)((t_keyval *)lst->content)->value);
			}
		}
		lst = lst->next;
	}
}
