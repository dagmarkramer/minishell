#include "minishell.h"

typedef struct	s_execute
{
	char		**arg;
	char		**env;
	t_list		*envlst;
	int			fd_input;
	int			fd_output;
}				t_execute;

typedef t_pipe t_execute;

char	**get_path_options(t_list *envlst)
{
	char	**paths;
	char	*unsplit;

	unsplit = ev_getenv("PATH", envlst);
	if (unsplit == NULL)
		return (NULL);
	paths = ft_split(unsplit, ':');
	ft_malloc_fail_check(paths);
	return (paths);
}

// this takes place in a child function (forked)
// only for non buildins that do not have an absolute path
void	execute_relative(t_execute *exe_info, t_list *envlst)
{
	char	**paths;
	char	*pathjoined;
	char	*tmp;
	int		i;

	i = 0;
	paths = get_path_options(envlst);
	if (paths == NULL)
		exit(127);
	while (paths[i] != NULL)
	{
		tmp = ft_strjoin(paths[i], "/");
		ft_malloc_fail_check(pathjoined);
		pathjoined = ft_strjoin(tmp, exe_info->arg[0]);
		ft_malloc_fail_check(pathjoined);
		execve(pathjoined, exe_info->arg, exe_info->env);	// run execve without envp?
		i++;
	}
	exit(127);
}

void	execute_absolute(t_execute *exe_info)
{
	execve(exe_info->arg[0], exe_info->arg, exe_info->env);	// run execve without envp?
	exit(127);
}

void	exe_child_process(t_execute *info)
{
	dup2(0, info->fd_input);
	dup2(1, info->fd_output);
	if(info->arg[0][0] == '/' || info->arg[0][0] == '.')
		execute_absolute(info);
	else
		execute_relative(info, info->envlst);	
}

int	exe_fork(t_execute *info)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_disruptive_exit("fork failed", 43);
	if (pid == 0)
		exe_child_process(info);
	waitpid(pid, &status, 0);
	return(WEXITSTATUS(status));
}

// arg is al gezet
// env wordt hier gezet (in de child functie?)
// fd input en output zijn al gezet
void	exe_pre_fork(t_execute *exe_info)
{
	// pipes are handled before this by the pipe fuctions, if there are redirecitons the pipe gets overwritten but first closed.
	// strip args of redirections and overwrite the i/o fds

	// then call the funciton where we fork and call the exec function!
	return (exe_fork(exe_info));
}
