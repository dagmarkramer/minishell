/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 19:31:23 by dkramer       #+#    #+#                 */
/*   Updated: 2022/03/09 13:16:04 by dkramer       ########   odam.nl         */
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

void	childprocess(int *pipefd, char **argv, char **newenv, t_pipex *pipex, int c)
{
	printf("child\n");
	if (close(pipefd[0]) == -1)
		exit(EXIT_FAILURE);
	getpathoptions(argv, c, pipex, newenv);
	pipex->args = malloc(sizeof(char *) * 4);
	if (!pipex->args)
		error_handling("malloc", pipex);
	pipex->args[0] = pipex->ls;
	if (pipex->options)
		pipex->args[1] = pipex->options;
	pipex->fd = open(argv[1], O_RDONLY);
	if (pipex->fd != -1)
		dup2(pipex->fd, 0);
	if (dup2(pipefd[1], 1) == -1)
		error_handling("dup2() error", pipex);
	ft_execute(pipex, newenv);
}

void	parentprocess(int *pipefd, char **argv, char **newenv, t_pipex *pipex, int c)
{
	printf("parent\n");
	if (close(pipefd[1]) == -1)
		exit(EXIT_FAILURE);
	getpathoptions(argv, c, pipex, newenv);
	pipex->args = malloc(sizeof(char *) * 4);
	if (!pipex->args)
		error_handling("malloc", pipex);
	pipex->args[0] = pipex->ls;
	if (pipex->options)
		pipex->args[1] = pipex->options;
	if (access(argv[5], F_OK) == 0 && access(argv[5], W_OK))
		error_handling(argv[5], pipex);
	pipex->fd = open(argv[5], O_RDWR | O_CREAT, 0666);
	if (pipex->fd == -1)
		error_handling(argv[5], pipex);
	if (dup2(pipex->fd, 1) == -1 || dup2(pipefd[0], 0) == -1)
		error_handling("dup2() error", pipex);
	ft_execute(pipex, newenv);
}

// void	childprocess4(int *pipefd, char **argv, char **newenv, t_pipex *pipex)
// {
// 	if (close(pipefd[1]) == -1)
// 		exit(EXIT_FAILURE);
// 	getpathoptions(argv, 4, pipex, newenv);
// 	pipex->args = malloc(sizeof(char *) * 4);
// 	if (!pipex->args)
// 		error_handling("malloc", pipex);
// 	pipex->args[0] = pipex->ls;
// 	if (pipex->options)
// 		pipex->args[1] = pipex->options;
// 	if (access(argv[5], F_OK) == 0 && access(argv[5], W_OK))
// 		error_handling(argv[5], pipex);
// 	pipex->fd = open(argv[5], O_RDWR | O_CREAT, 0666);
// 	if (pipex->fd == -1)
// 		error_handling(argv[5], pipex);
// 	if (dup2(pipex->fd, 1) == -1 || dup2(pipefd[0], 0) == -1)
// 		error_handling("dup2() error", pipex);
// 	ft_execute(pipex, newenv);
// }

int	main(int argc, char **argv, char **newenv)
{
	int		**pipefd;
	t_pipex	*pipex;

	printf("hi\n");
	(void)argc;
	pipex = malloc(sizeof(t_pipex));
	pipefd = malloc(sizeof(int *) * 3);
	pipefd[0] =  malloc(sizeof(int) * 3);
	pipefd[1] =  malloc(sizeof(int) * 3);
	// if (argc != 5)
	// 	exit(EXIT_FAILURE);
	int i;
	int	c;

	i = 0;
	c = 2;
	while (i < 1)
	{
		if (pipe(pipefd[i]) == -1)
			error_handling("pipe", pipex);
		pipex->cpid = fork();
		if (pipex->cpid == -1)
			error_handling("fork", pipex);
		if (pipex->cpid == 0)
			childprocess(pipefd[i], argv, newenv, pipex, c);
		if (i < 1)
			pipefd[i + 1][0] = pipefd[i][1];
		i++;
		c++;
	}
	sleep(1);
	if (pipex->cpid != 0)
		parentprocess(pipefd[0], argv, newenv, pipex, c);
	return (0);
}
