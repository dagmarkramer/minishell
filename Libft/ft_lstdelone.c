/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:46:44 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/20 17:19:39 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *ptr, void (*del)(void *))
{
	if (!ptr || !del)
		return ;
	del(ptr->content);
	free(ptr);
}
