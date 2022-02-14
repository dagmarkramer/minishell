/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:46:32 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/20 14:42:32 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **ptr, t_list *new)
{
	if (!(ptr) || !(new))
		return ;
	new->next = *ptr;
	*ptr = new;
}
