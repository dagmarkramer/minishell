/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/14 17:44:09 by dkramer       #+#    #+#                 */
/*   Updated: 2022/03/09 12:20:22 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include "pipex.h"
#include <fcntl.h>
#include <errno.h>

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

void	getpath(char **newenv, t_pipex *pipex)
{
	int		i;
	char	**split;

	i = 0;
	while (newenv[i])
	{
		if (ft_strnstr(newenv[i], "PATH=", ft_strlen(newenv[i])))
		{
			split = ft_split(newenv[i], '=');
			if (!split)
				error_handling("malloc", pipex);
			pipex->path = ft_strdup(split[1]);
		}
		i++;
	}
	free (split[0]);
	free (split[1]);
	free (split);
}

void	getpathoptions(char **argv, int argint, t_pipex *pipex, char **newenv)
{
	pipex->split = ft_split(argv[argint], ' ');
	if (!pipex->split)
		error_handling("malloc", pipex);
	pipex->ls = ft_strdup(pipex->split[0]);
	if (!pipex->ls)
		error_handling("malloc", pipex);
	pipex->options = NULL;
	if (pipex->split[1])
	{
		pipex->options = ft_strdup(pipex->split[1]);
		if (!pipex->options)
			error_handling("malloc", pipex);
	}
	// printf("%d\n", argint);
	free (pipex->split[0]);
	free (pipex->split[1]);
	free (pipex->split);
	getpath(newenv, pipex);
	pipex->path2d = ft_split(pipex->path, ':');
	free (pipex->path);
	if (!pipex->split)
		error_handling("malloc", pipex);
}
