#include "minishell.h"

typedef struct	s_execute
{
	char		**argv;
	int			fd_input;
	int			fd_output;
}				t_execute;

void	ft_execute(t_pipex *pipex, char **newenv)
{
	int		i;
	char	*pathjoined;

	i = -1;
	// printf("%s\n", pipex->ls);
	while (pipex->path2d[i + 1])
	{
		i++;
		pathjoined = ft_strjoin(pipex->path2d[i], "/");
		if (!pathjoined)
			error_handling("malloc", pipex);
		pathjoined = ft_strjoin(pathjoined, pipex->ls);
		if (!pathjoined)
			error_handling("malloc", pipex);
		execve(pathjoined, pipex->args, newenv);
	}
	exit (127);
}

char	**get_path_options(t_list *envlst)
{
	char	**paths;
	char	*unsplit;

	unsplit = ev_getenv("PATH", envlst); // malloced in linked list so do not need to free
	if (unsplit == NULL)
		return (0); // exception
	paths = ft_split(unsplit, ':');
	ft_malloc_fail_check(path);
	return (paths);
}

// this takes place in a child function (forked)
void	ft_execute(t_execute *exe_info, t_list *envlst)
{
	char	**paths;
	char	*pathjoined;
	int		i;

	i = 0;
	paths = get_path_options(envlst);
	while (paths[i] != NULL)
	{
		pathjoined = ft_strjoin(paths[i], "/");		//strjoin leaks ?
		ft_malloc_fail_check(pathjoined);
		pathjoined = ft_strjoin(pathjoined, pipex->ls);		// what is mini or pipe->ls ?
		ft_malloc_fail_check(pathjoined);
		execve(pathjoined, pipex->args, newenv);
		i++;
	}
	exit(127);
	// execve(path, exe_info->argv, env);
}
