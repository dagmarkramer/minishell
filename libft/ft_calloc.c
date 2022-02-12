/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 15:17:06 by dagmarkrame   #+#    #+#                 */
/*   Updated: 2021/12/09 10:47:51 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

void	*ft_calloc(size_t count, size_t size)
{
	char			*ptr;
	unsigned long	i;
	void			*ptr1;

	i = 0;
	ptr = malloc(size * count);
	if (ptr == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	if (ptr != NULL)
	{
		while (i < (count * size))
		{
			ptr[i] = '\0';
			i++;
		}
	}
	ptr1 = (void *)ptr;
	return (ptr1);
}
