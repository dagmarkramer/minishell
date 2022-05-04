#include <stddef.h>
#include <stdlib.h>

int	ft_arraylen(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	free_string_array(char **arr)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)arr;
	if (strings == NULL)
		return ;
	while (strings[i] != NULL)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}
