#include "minishell.h"

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
		ft_malloc_fail_check(tmp);
		pathjoined = ft_strjoin(tmp, exe_info->arg[0]);
		ft_malloc_fail_check(pathjoined);
		execve(pathjoined, exe_info->arg, 0);	// run execve without envp? seems to work
		i++;
	}
	exit(127);
}

void	execute_absolute(t_execute *exe_info)
{
	execve(exe_info->arg[0], exe_info->arg, 0);	// run execve without envp? exe_info->env
	exit(127);
}

void	exe_child_process(t_execute *info)
{
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

int	exe_pre_fork(t_pipe *pipe, t_mini *data)
{
	t_execute	info;
	int			ret;

	exe_pipe_to_execute(pipe, &info, data);
	info.arg = fd_redirections(&info);

	dup2(info.fd_input, 0);
	dup2(info.fd_output, 1);
	ret = exe_fork(&info);
	close(info.fd_input);
	close(info.fd_output);
	fd_cleanup(data);

	return (ret);
}
