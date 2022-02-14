/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:17:36 by dagmarkrame   #+#    #+#                 */
/*   Updated: 2020/12/01 13:58:20 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	c1;

	str1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		if (str1[i] == c1)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
