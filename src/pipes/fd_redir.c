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

void	fd_redirect(t_execute *info, int index)
{
	if (ft_strncmp(info->arg[index], "<<", 2))
	{
		// heredoc
	}
	else if (ft_strncmp(info->arg[index], ">>", 2))
	{
		// append mode
	}
	else if (ft_strncmp(info->arg[index], ">", 1))
	{
		// overwrite (write to)
	}
	else
	{
		// read mode
	}
}

char	**fd_redirections(t_execute *info)
{
	int	i;

	i = 0;
	while (info->arg[i] != NULL)
	{
		if (info->arg[i][0] == '<' || info->arg[i][0] == '>')
			fd_redirect(info, i)
		i++;
	}
	return (info->arg);
}
