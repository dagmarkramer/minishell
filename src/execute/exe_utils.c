/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exe_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:47:00 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/11 14:08:12 by obult         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	exe->fd_input = pipe->input_fd;
	exe->fd_output = pipe->output_fd;
	exe->arg = pipe->tokens;
	exe->envlst = data->env;
	exe->env = data->environ;
	pipe->tokens = NULL;
	return (exe);
}
