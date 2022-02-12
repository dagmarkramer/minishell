/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:22:42 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/20 13:53:37 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst1;
	unsigned char	c1;
	unsigned int	i;

	c1 = (unsigned char)c;
	dst1 = (unsigned char *)b;
	i = 0;
	while (len > i)
	{
		dst1[i] = c1;
		i++;
	}
	return (b);
}
