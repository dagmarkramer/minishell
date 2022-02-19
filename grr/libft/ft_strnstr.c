/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:27:56 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:09:34 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_ftloop(char *haystack1, const char *needle, size_t len)
{
	unsigned int	c;
	unsigned int	d;

	c = 0;
	d = 0;
	while (haystack1[c] != '\0' && needle[d] != '\0' && len >= c)
	{
		while ((haystack1[c] == needle[d] || needle[d] == '\0') && len >= c)
		{
			if (needle[d] == '\0')
				return (&haystack1[c - d]);
			c++;
			d++;
			if (haystack1[c] != needle[d] && needle[d] != '\0')
			{
				c--;
				break ;
			}
		}
		d = 0;
		c++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *hs, const char *needle, size_t len)
{
	char			*haystack1;

	haystack1 = (char *)hs;
	if (needle[0] == '\0')
		return (&haystack1[0]);
	return (ft_ftloop(haystack1, needle, len));
}
