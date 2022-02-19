/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 11:46:09 by dkramer       #+#    #+#                 */
/*   Updated: 2021/03/09 17:23:01 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*one;

	one = (t_list *)malloc(sizeof(t_list));
	if (one == NULL)
		return (NULL);
	one->content = content;
	one->next = NULL;
	return (one);
}
