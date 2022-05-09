/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:47:57 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/10 00:34:25 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_exit(char **array)
{
	int	exitcode;
	int	errorcode;
	int	arraylen;

	errorcode = 0;
	arraylen = ft_arraylen((void *)array);
	if (arraylen > 2)
	{
		printf("OGS: exit: too many arguments\n");
		return (1);
	}
	if (arraylen == 1)
		exit(0);
	exitcode = ph_atoi(array[1], &errorcode);
	if (errorcode != 0)
	{
		printf("OGS: exit: %s: numeric argument required\n", array[1]);
		exit(255);
	}
	exit(exitcode);
	return (0);
}
