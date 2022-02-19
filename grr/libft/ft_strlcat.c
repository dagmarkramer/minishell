/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:29:53 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:08:18 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_loopdst(char *dst, const char *src, size_t dstsize)
{
	size_t			final;

	final = ft_strlen(src) + ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (ft_strlen(dst) > dstsize)
		return (dstsize + ft_strlen(src));
	return (final);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	save;
	size_t			final;

	i = 0;
	j = 0;
	final = ft_strlen(src) + ft_strlen(dst);
	if (ft_loopdst(dst, src, dstsize) != ft_strlen(src) + ft_strlen(dst))
		return (ft_loopdst(dst, src, dstsize));
	while (dst[j] != '\0')
	{
		j++;
	}
	save = ft_strlen(dst);
	while ((save + i + 1) < dstsize && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	if (save < dstsize)
		dst[j] = '\0';
	return (final);
}
