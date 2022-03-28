/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:25:45 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/15 13:34:20 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*new;
	unsigned int	h;

	i = 0;
	h = 0;
	if (!s1 || !s2)
		return (0);
	new = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[h] != '\0')
	{
		new[i] = s2[h];
		i++;
		h++;
	}
	new[i] = '\0';
	return (new);
}
