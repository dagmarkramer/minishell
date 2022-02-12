/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:17:32 by dagmarkrame   #+#    #+#                 */
/*   Updated: 2020/11/25 11:01:36 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dst1;
	unsigned char	*src1;
	unsigned char	c1;

	c1 = (unsigned char)c;
	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		dst1[i] = src1[i];
		if (src1[i] == c1)
			return ((void *)&dst1[i + 1]);
		i++;
	}
	return (NULL);
}
