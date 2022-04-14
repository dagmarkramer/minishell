#include "minishell.h"

// char	**envlist_to_array(t_list *envlst)
// {
// 	t_dictionary	*env_item;
// 	char			**envarray;
// 	int				lstsize;

// 	lstsize = ft_lstsize(envlst);
	
// 	while (envlst)
// 	{

// 	}
// }

void	fd_replacer(int *to_replace, int new_fd)
{
	if (*to_replace > 2)
		close(*to_replace);
	*to_replace = new_fd;
}

void	fd_open_and_replace(int *to_replace, char *filename)
{
	int	new_fd;

	new_fd = open(filename, O_RDWR);
	if (*to_replace > 2)
		close(*to_replace);
	if (new_fd != -1)
		*to_replace = new_fd;
}
