/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:32:15 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/15 15:33:19 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s1;
	char	c1;

	s1 = (char *)s;
	c1 = (char)c;
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i++;
	}
	if (s1[i] == c1 && c1 != '\0')
		return (&s1[i]);
	if (s1[i] == '\0' && c1 == '\0')
		return (&s1[i]);
	return (NULL);
}
