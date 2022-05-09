#include "minishell.h"

void	execute_relative(t_execute *info, t_list *env)
{
	char	**paths;
	char	*pathjoined;
	char	*tmp;
	int		i;

	i = 0;
	paths = get_path_options(env);
	if (paths == NULL)
		exit(127);
	while (paths[i] != NULL)
	{
		tmp = ft_strjoin(paths[i], "/");
		ft_malloc_fail_check(tmp);
		pathjoined = ft_strjoin(tmp, info->arg[0]);
		ft_malloc_fail_check(pathjoined);
		execve(pathjoined, info->arg, ft_lst_to_array(env, ev_turn_envlist));
		i++;
	}
	exit(127);
}

void	execute_absolute(t_execute *info, t_list *env)
{
	execve(info->arg[0], info->arg, ft_lst_to_array(env, ev_turn_envlist));
	exit(127);
}

void	exe_child_process(t_execute *info, t_mini *data)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	dup2(info->fd_input, 0);
	dup2(info->fd_output, 1);
	if (is_buildin(info->arg[0]))
		exe_buildin(info, data);
	else if (info->arg[0][0] == '/' || info->arg[0][0] == '.')
		execute_absolute(info, info->envlst);
	else
		execute_relative(info, info->envlst);
	exit(0);
}

int	exe_fork(t_execute *info, t_mini *data)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_disruptive_exit("fork failed", 43);
	if (pid == 0)
		exe_child_process(info, data);
	ms_parenting_signals();
	waitpid(pid, &status, 0);
	ms_signals();
	if (WIFSIGNALED(status))
		return (130);
	return (WEXITSTATUS(status));
}

int	exe_pre_fork(t_pipe *pipe, t_mini *data)
{
	t_execute	info;
	int			ret;

	exe_pipe_to_execute(pipe, &info, data);
	info.arg = fd_redirections(&info);
	ret = exe_fork(&info, data);
	if (ret == 127)
		printf("OGS: %s: command not found\n", info.arg[0]);
	free_string_array(info.arg);
	close(info.fd_input);
	close(info.fd_output);
	fd_cleanup(data);
	return (ret);
}
