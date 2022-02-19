/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 15:51:09 by dkramer       #+#    #+#                 */
/*   Updated: 2021/01/21 11:31:10 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s1, int n, int d)
{
	int		end;
	char	temp;
	int		start;
	int		tempend;

	start = 0;
	if (n < 0)
		start = 1;
	end = d - 1 + start;
	tempend = end;
	while (end >= start)
	{
		temp = s1[start];
		s1[start] = s1[end];
		s1[end] = temp;
		start++;
		end--;
	}
	s1[tempend + 1] = '\0';
	return (s1);
}
