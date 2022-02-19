/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:47:12 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:06:35 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *ptr)
{
	unsigned int				i;

	if (!ptr)
		return (0);
	i = 1;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
