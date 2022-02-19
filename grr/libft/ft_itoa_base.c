/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 17:13:55 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:13:55 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ibstrrev(char *s1, int d)
{
	int		end;
	char	temp;
	int		start;
	int		tempend;

	start = 0;
	end = d - 1 + start;
	tempend = end;
	while (end >= start)
	{
		temp = s1[start];
		s1[start] = s1[end];
		s1[end] = temp;
		start++;
		end--;
	}
	s1[tempend + 1] = '\0';
	return (s1);
}

static int	ft_ullnrofdigits(unsigned long long n, int blen)
{
	int	d;

	d = 0;
	while (n != 0)
	{
		n = n / blen;
		d++;
	}
	return (d);
}

static char	*ft_makestring(char *backwards, unsigned long long n,
	char *base, int blen)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		backwards[i] = base[n % blen];
		n = n / blen;
		i++;
	}
	backwards[i] = '\0';
	return (backwards);
}

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char	*backwards;
	int		d;
	int		blen;

	if (n == 0)
		return (ft_strdup("0"));
	blen = ft_strlen(base);
	d = ft_ullnrofdigits(n, blen);
	backwards = malloc(d + 1);
	if (backwards == NULL)
		return (NULL);
	backwards = ft_makestring(backwards, n, base, blen);
	return (ft_ibstrrev(backwards, d));
}
