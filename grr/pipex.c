/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 19:31:23 by dkramer       #+#    #+#                 */
/*   Updated: 2022/02/05 16:41:46 by dkramer       ########   odam.nl         */
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
#include <sys/errno.h>

void	error_handling(char *error_message, t_pipex *pipex)
{
	free (pipex);
	perror(error_message);
	exit(EXIT_FAILURE);
}

void	parentprocess(int *pipefd, char **argv, char **newenv, t_pipex *pipex)
{
	if (close(pipefd[0]) == -1)
		exit(EXIT_FAILURE);
	getpathoptions(argv, 2, pipex, newenv);
	pipex->args = malloc(sizeof(char *) * 4);
	if (!pipex->args)
		error_handling("malloc", pipex);
	pipex->args[0] = pipex->ls;
	if (pipex->options)
		pipex->args[1] = pipex->options;
	pipex->fd = open(argv[1], O_RDONLY);
	if (pipex->fd == -1)
		error_handling(argv[1], pipex);
	if (dup2(pipex->fd, 0) == -1 || dup2(pipefd[1], 1) == -1)
		error_handling("dup2() error", pipex);
	ft_execute(pipex, newenv);
}

void	childprocess(int *pipefd, char **argv, char **newenv, t_pipex *pipex)
{
	if (close(pipefd[1]) == -1)
		exit(EXIT_FAILURE);
	getpathoptions(argv, 3, pipex, newenv);
	pipex->args = malloc(sizeof(char *) * 4);
	if (!pipex->args)
		error_handling("malloc", pipex);
	pipex->args[0] = pipex->ls;
	if (pipex->options)
		pipex->args[1] = pipex->options;
	if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK))
		error_handling(argv[4], pipex);
	pipex->fd = open(argv[4], O_RDWR | O_CREAT, 0666);
	if (pipex->fd == -1)
		error_handling(argv[4], pipex);
	if (dup2(pipex->fd, 1) == -1 || dup2(pipefd[0], 0) == -1)
		error_handling("dup2() error", pipex);
	ft_execute(pipex, newenv);
}

int	main(int argc, char *argv[], char **newenv)
{
	int		pipefd[2];
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (argc != 5)
		exit(EXIT_FAILURE);
	if (pipe(pipefd) == -1)
		error_handling("pipe", pipex);
	pipex->cpid = fork();
	if (pipex->cpid == -1)
		error_handling("fork", pipex);
	if (pipex->cpid == 0)
		childprocess(pipefd, argv, newenv, pipex);
	else
		parentprocess(pipefd, argv, newenv, pipex);
	return (0);
}
