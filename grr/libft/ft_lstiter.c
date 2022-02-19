/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:46:53 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/20 20:37:39 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *ptr, void (*f)(void *))
{
	if (!ptr || !f)
		return ;
	while (ptr != NULL)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}
