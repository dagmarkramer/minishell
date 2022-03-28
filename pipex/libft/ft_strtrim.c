/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:26:07 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:09:52 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findstart(char const *s1, char const *set)
{
	int		j;
	int		i;
	int		start;

	i = 0;
	j = 0;
	while (set[j] != '\0' && s1[i] != '\0')
	{
		while (set[j] == s1[i])
		{
			j = 0;
			i++;
		}
		j++;
	}
	start = i;
	return (start);
}

static int	ft_findend(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	end;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (set[j] != '\0' && s1[i] != '\0')
	{
		while (set[j] == s1[i])
		{
			j = 0;
			i--;
		}
		j++;
	}
	i++;
	end = i;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trim;
	unsigned int	start;
	unsigned int	end;

	end = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	else
		start = ft_findstart(s1, set);
	if (s1[start] == '\0')
		end = start;
	else
		end = ft_findend(s1, set);
	trim = ft_substr(s1, start, (end - start));
	if (trim == NULL)
		return (NULL);
	return (trim);
}
