/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 13:06:36 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:00:10 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;
	char			*dst1;

	dst1 = (char *)s;
	i = 0;
	while (n > i)
	{
		dst1[i] = 0;
		i++;
	}
}
