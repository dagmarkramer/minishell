/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:29:36 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:08:37 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	size_t			final;

	i = 0;
	j = 0;
	if (!dst && !src)
		return (0);
	while (dstsize > (i + 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	while (src[j] != '\0')
	{
		j++;
	}
	final = j;
	return (final);
}
