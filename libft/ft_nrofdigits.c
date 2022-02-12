/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nrofdigits.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 17:13:43 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:07:12 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nrofdigits(long long int n, int blen)
{
	int	d;

	d = 0;
	if (n == 0)
		d++;
	if (n < 0)
	{
		d++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / blen;
		d++;
	}
	return (d);
}
