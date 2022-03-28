/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 20:18:17 by dkramer       #+#    #+#                 */
/*   Updated: 2022/03/28 14:00:59 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_pipex
{
	char	**split;
	char	*ls;
	char	*options;
	char	*path;
	char	**path2d;
	char	*hs;
	char	*hs2;
	char	*hs3;
	char	**args;
	int		fdin;
	int		fdout;
	char	*extraoptions;
	pid_t	cpid;
	int		malloc;
}				t_pipex;

void	ft_execute(t_pipex *pipex, char **newenv);
void	getpathoptions(char **argv, int argint, t_pipex *pipex, char **newenv);
void	error_handling(char *error_message, t_pipex *pipex);

#endif