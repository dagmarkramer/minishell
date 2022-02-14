/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:46:25 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/20 20:26:56 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **ptr, t_list *new)
{
	if (!(ptr) || !new)
		return ;
	if ((*ptr) == NULL)
	{
		(*ptr) = new;
		return ;
	}
	while ((*ptr)->next != NULL)
	{
		(*ptr) = (*ptr)->next;
	}
	(*ptr)->next = new;
}
