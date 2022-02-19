/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:25:36 by dkramer       #+#    #+#                 */
/*   Updated: 2021/02/26 20:08:06 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_clean(char **array, int len)
{
	while (len > 0)
	{
		free(array[len - 1]);
		len--;
	}
	free(array);
	return (NULL);
}

static int	ft_amount(char const *s, char c, int i)
{
	int		count;

	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			i++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

static char	**ft_loop(char const *s, char **array, char c, int amount)
{
	size_t			end;
	unsigned int	start;
	int				i;
	char			*tmp2;

	tmp2 = (char *)s;
	i = 0;
	start = 0;
	while (i < amount)
	{
		end = 0;
		while (tmp2[start] == c && tmp2[start] != '\0')
			start++;
		while (tmp2[end + start] != c && tmp2[end + start] != '\0')
			end++;
		array[i] = ft_substr(s, start, end);
		if (array[i] == NULL)
			return (ft_clean(array, i));
		i++;
		while (tmp2[start] != c && tmp2[start] != '\0')
			start++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		amount;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	amount = ft_amount(s, c, i);
	array = malloc((amount + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = ft_loop(s, array, c, amount);
	return (array);
}
