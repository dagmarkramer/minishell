/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_echo.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:47:49 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/11 14:17:11 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	Simple function which just prints out an array of strings with spaces
 *	inbetween.
 *	Does not end with a newline.
 */

static void	eo_printarray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		write(1, array[i], ft_strlen(array[i]));
		if (array[i + 1] != NULL)
			write(1, " ", 1);
		i++;
	}
}

/*
 *	Count strings with just -n in them or a dash with multiple n's
 */

int	eo_dash_n_count(char **array)
{
	int	count;
	int	i;

	count = 0;
	while (array[count] && array[count][0] == '-' && array[count][1] == 'n')
	{
		i = 1;
		while (array[count][i])
		{
			if (array[1][i] != 'n')
				return (count);
			i++;
		}
		count++;
	}
	return (count);
}

/*
 *	Replication of the BASH echo command.
 *	Writes out an array without the echo required as first argument.
 *	Ends with or without a newline based on the presence of -n flag.
 */

void	ms_echo(char **array)
{
	int	i;
	int	ncount;

	i = 1;
	if (ft_strncmp(array[0], "echo", 5) != 0)
		return ;
	ncount = eo_dash_n_count(&array[1]);
	eo_printarray(&array[1 + ncount]);
	if (ncount == 0)
		write(1, "\n", 1);
}
