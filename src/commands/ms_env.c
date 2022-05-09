/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_env.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:47:53 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/09 22:47:54 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_env(t_mini *mini, char **array)
{
	if (ft_strncmp(array[0], "env", 4) != 0)
		return ;
	ft_printlst(mini->env, "env");
}
