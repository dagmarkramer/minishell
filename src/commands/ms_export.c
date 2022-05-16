/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_export.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:48:00 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/16 16:36:13 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_export(t_mini *mini, char **array)
{
	char	*key;
	char	*value;
	int		i;

	i = 1;
	ev_sort_alfa(mini->env);
	key = NULL;
	value = NULL;
	while (array[i] != NULL)
	{
		if (!ft_isallnotalpha(array[i]))
			ft_putstringtostderror(array[i], " : not a valid identifier");
		else
		{
			key = ft_strcdup(array[i], '=');
			ft_malloc_fail_check(key);
			if (ft_strchr(array[i], '='))
				value = ft_strdup(&array[i][ft_strclen(array[i], '=') + 1]);
			if (ev_change_env(key, value, &mini->env))
				ft_disruptive_exit("malloc fail", 1);
		}
		i++;
	}
	if (array[1] == NULL)
		ft_printlst(mini->env, "export");
}
