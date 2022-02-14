/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:46:58 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:05:58 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *ptr)
{
	if (!ptr)
		return (0);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	return (ptr);
}
