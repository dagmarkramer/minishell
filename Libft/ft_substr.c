/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:26:15 by dkramer       #+#    #+#                 */
/*   Updated: 2020/11/29 09:47:20 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*makesubstr(char const *s, unsigned int start, size_t len, char *substr)
{
	unsigned int	i;
	unsigned int	c;
	unsigned int	save;

	save = ft_strlen(s);
	c = 0;
	i = 0;
	while (s[i] != '\0' && i < start)
		i++;
	while ((c < len && (save - start) >= len && s[i] != '\0')
		|| (c < (save) && (save - start) < len && s[i] != '\0'))
	{
		substr[c] = s[i];
		c++;
		i++;
	}
	substr[c] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	save;

	if (!s)
		return (NULL);
	save = ft_strlen(s);
	if (save - start >= len)
		substr = malloc(sizeof(char) * (len + 1));
	else
		substr = malloc(sizeof(char) * (save + 1 - start));
	if (substr == NULL)
		return (NULL);
	return (makesubstr(s, start, len, substr));
}
