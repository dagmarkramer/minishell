#include "minishell.h"

// echo cd pwd export unset env exit
int	is_buildin(char *command)
{
	return (!ft_strcmp(command, "echo") || !ft_strcmp(command, "cd")
		|| !ft_strcmp(command, "pwd") || !ft_strcmp(command, "export")
		|| !ft_strcmp(command, "unset") || !ft_strcmp(command, "env")
		|| !ft_strcmp(command, "exit"));
}

// link the buildin functions with if statements
int	exe_buildin(t_execute *info, t_mini *data)
{
	if (ft_strcmp(info->arg[0], "echo") == 0)
		ms_echo(info->arg);
	if (ft_strcmp(info->arg[0], "cd") == 0)
		ms_cd(info->arg);
	if (ft_strcmp(info->arg[0], "env") == 0)
		ms_env(data, info->arg);
	if (ft_strcmp(info->arg[0], "exit") == 0)
		ms_exit(info->arg);
	if (ft_strcmp(info->arg[0], "export") == 0)
		ms_export(data, info->arg);
	if (ft_strcmp(info->arg[0], "pwd") == 0)
		ms_pwd(info->arg);
	if (ft_strcmp(info->arg[0], "unset") == 0)
		ms_unset(data);
	return (0);
}

int	exe_pre_buildin(t_pipe *pipe, t_mini *data)
{
	t_execute	info;
	int			tmp;

	exe_pipe_to_execute(pipe, &info, data);
	info.arg = fd_redirections(&info);

	dup2(info.fd_input, 0);
	dup2(info.fd_output, 1);
	tmp = exe_buildin(&info, data);
	free_string_array(info.arg);
	close(info.fd_input);
	close(info.fd_output);
	fd_cleanup(data);
	return (tmp);
}
