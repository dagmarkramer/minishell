/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_cd.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:47:42 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/11 18:05:01 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	takes the argument array from the input including cd as arg[0]
 *	returns a ZERO on succes and ONE on failure
 *	to many arguments OR invalid directory as an argument results in failure
 */

int	ms_cd(char **array, t_list *env)
{
	if (ft_arraylen(array) > 2)
	{
		printf("OGS: cd: too many arguments\n");
		return (1);
	}
	if (ft_strncmp(array[0], "cd", 3) != 0)
		return (1);
	if (array[1] == NULL)
	{
		if (chdir(ev_getenv("HOME", env)))
		{
			perror(array[1]);
			return (1);
		}
		return (0);
	}
	if (chdir(array[1]))
	{
		perror(array[1]);
		return (1);
	}
	return (0);
}
