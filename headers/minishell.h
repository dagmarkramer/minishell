/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:42:27 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/14 14:16:45 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define READ 0
# define WRITE 1

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <unistd.h>
# include <sys/stat.h>
# include <stdbool.h>

# include "readline/readline.h"
# include "readline/history.h"

# include "libft.h"
# include "ms_environ.h"
# include "tokenizer.h"
# include "execution.h"
# include "commands.h"

typedef struct s_keyval
{
	char	*key;
	char	*value;
}				t_keyval;

typedef t_keyval	t_dictionary;

typedef struct s_mini
{
	char	*input;
	char	**environ;
	t_list	*env;
	int		save_out;
	int		save_in;
	int		last_return;
}				t_mini;

// MODULES
void	ms_signals(void);
void	ms_parenting_signals(void);
int		ms_lexer(t_list *tokens);
t_list	*ms_parser(t_list **tokens);
void	ms_line_executer(t_mini *data);
int		ms_heredoc(char *delimiter);
void	replaceexitstatus(t_mini *data);

// UTILS
void	ft_disruptive_exit(char *exit_status, int exit_int);
void	ft_malloc_fail_check(void *status);
void	ft_strcpy(char *dst, char *src);
int		ft_strclen(char *str, char c);
int		ft_strslen(char *str, char *check);
char	*ft_strcdup(const char *s1, char c);
int		ft_strcmp(const char *s1, const char *s2);

char	**ft_lst_to_array(t_list *lst, void (*turn)(void *, char **));
void	ev_turn_envlist(void *content, char **dst);

// Wildcards bonus
void	wildcards_expander(t_list **tokens);

#endif
