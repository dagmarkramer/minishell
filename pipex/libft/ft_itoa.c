/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 14:16:00 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:14:11 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_decnrofdigits(int n)
{
	int	d;

	d = 0;
	while (n != 0)
	{
		n = n / 10;
		d++;
	}
	return (d);
}

static int	ft_getc(int n)
{
	int		c;

	c = 0;
	if (n < 0)
		c = 1;
	return (c);
}

static char	*ft_makestring(char *backwards, int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		backwards[i] = '-';
		n = n * -1;
		i++;
	}
	while (n != 0)
	{
		backwards[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	return (backwards);
}

char	*ft_itoa(int n)
{
	char	*backwards;
	int		tempn;
	int		d;

	tempn = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	d = ft_decnrofdigits(n);
	backwards = malloc(d + ft_getc(n) + 1);
	if (backwards == NULL)
		return (NULL);
	backwards = ft_makestring(backwards, n);
	return (ft_strrev(backwards, tempn, d));
}
