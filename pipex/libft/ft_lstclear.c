/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:46:39 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:05:46 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst)
		return ;
	ptr = *lst;
	while ((*lst) != NULL)
	{
		ptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = ptr;
	}
	lst = NULL;
}
