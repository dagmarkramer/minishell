/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_exit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:47:57 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/16 14:26:34 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ms_exit(char **array, int last_return)
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
		exit(last_return);
	exitcode = ph_atoi(array[1], &errorcode);
	if (errorcode != 0)
	{
		printf("OGS: exit: %s: numeric argument required\n", array[1]);
		exit(255);
	}
	exit(exitcode);
}
