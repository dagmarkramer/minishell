/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_unset.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:48:09 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/09 22:48:10 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_unset(char **args, t_mini *mini)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		ev_rem_env(args[i], &mini->env);
		i++;
	}
}
