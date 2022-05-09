/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:42:19 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/09 22:42:21 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "libft.h"
# include "minishell.h"

typedef struct s_mini	t_mini;

typedef struct s_pipe
{
	int		input_fd;
	int		output_fd;
	char	**tokens;
}				t_pipe;

typedef struct s_execute
{
	char		**arg;
	char		**env;
	t_list		*envlst;
	int			fd_input;
	int			fd_output;
}				t_execute;

// HEREDOC
int			ms_heredoc(char *delimiter);
char		*ft_stradd(char *str1, char *str2);

// FD_REDIRECTION
char		**fd_redirections(t_execute *info);
void		fd_close(int fd);
void		fd_replacer(int *to_replace, int new_fd);
void		fd_cleanup(t_mini *data);

// EXE_UTILS
t_execute	*exe_pipe_to_execute(t_pipe *pipe, t_execute *exe, t_mini *data);
char		**get_path_options(t_list *envlst);

// EXE_BUILDIN
int			is_buildin(char *command);
int			exe_buildin(t_execute *info, t_mini *data);
int			exe_pre_buildin(t_pipe *pipe, t_mini *data);

// EXECUTE
int			exe_pre_fork(t_pipe *pipe, t_mini *data);

// PARSER (duplicate declaration in minishell.h)
t_list		*ms_parser(t_list **tokens);

#endif