/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:17:29 by dkramer       #+#    #+#                 */
/*   Updated: 2021/03/07 11:10:15 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

// char	*ft_strdup(const char *s1)
// {
// 	int		i;
// 	char	*copy;

// 	i = 0;
// 	copy = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
// 	if (copy == NULL)
// 	{
// 		return (NULL);
// 	}
// 	while (s1[i] != '\0')
// 	{
// 		copy[i] = s1[i];
// 		i++;
// 	}
// 	copy[i] = '\0';
// 	return (copy);
// }

int	ft_intstrchr(const char *s, int mode)
{
	int		i;
	char	*s1;

	s1 = (char *)s;
	i = 0;
	if (mode == 0)
	{
		while (s1[i] != '\0')
		{
			if (s1[i] == '\n')
				return (1);
			i++;
		}
		return (0);
	}
	else
	{
		while (s1[i] != '\0')
		{
			if (s1[i] == '\n')
				break ;
			i++;
		}
		return (i);
	}
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char			*substr;
// 	unsigned int	save;
// 	unsigned int	i;
// 	unsigned int	c;

// 	if (!s)
// 		return (NULL);
// 	save = ft_strlen(s);
// 	substr = malloc(sizeof(char) * (len + 1));
// 	if (substr == NULL)
// 		return (NULL);
// 	c = 0;
// 	i = 0;
// 	while (s[i] != '\0' && i < start)
// 		i++;
// 	while (c < len && i < save)
// 	{
// 		substr[c] = s[i];
// 		c++;
// 		i++;
// 	}
// 	substr[c] = '\0';
// 	return (substr);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	unsigned int	i;
// 	char			*new;
// 	unsigned int	h;

// 	i = 0;
// 	h = 0;
// 	if (!s1 || !s2)
// 		return (0);
// 	new = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)));
// 	if (new == NULL)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		new[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[h] != '\0')
// 	{
// 		new[i] = s2[h];
// 		i++;
// 		h++;
// 	}
// 	new[i] = '\0';
// 	return (new);
// }
