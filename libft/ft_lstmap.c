/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:47:07 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:06:13 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*rlst;

	if (!lst || !f)
		return (NULL);
	rlst = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&rlst, del);
			return (NULL);
		}
		ft_lstadd_back(&rlst, new);
		lst = lst->next;
	}
	return (rlst);
}
