#include "minishell.h"

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

t_execute	*exe_pipe_to_execute(t_pipe *pipe, t_execute *exe, t_mini *data)
{
	t_list	*envlst;
	char	**env;

	envlst = data->env;
	env = data->environ;
	exe->fd_input = pipe->input_fd;
	exe->fd_output = pipe->output_fd;
	exe->arg = pipe->tokens;
	exe->envlst = envlst;
	exe->env = env;
	free(pipe);
	return (exe);
}
