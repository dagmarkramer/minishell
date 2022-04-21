#ifndef MINISHELL_H
# define MINISHELL_H

# define READ 0
# define WRITE 1
#  include <stdio.h>
#  include "readline/readline.h"
#  include "readline/history.h"
#  include <stdlib.h>
#  include "libft.h"
#  include <fcntl.h>
#  include <limits.h>
#  include <dirent.h>
#  include <termios.h>
#  include <curses.h>
#  include <term.h>
#  include <signal.h>
#  include <unistd.h>
#  include <sys/stat.h>
#  include "tokenizer.h"
#  include "ms_environ.h"
#  include <stdbool.h>
#  include "execution.h"
#  include "commands.h"

typedef	struct s_keyval
{
	char	*key;
	char	*value;
}				t_keyval;

typedef t_keyval t_dictionary;

typedef struct s_mini
{
	char	*input;
	char 	**environ;
	t_list	*env;
	int		save_out;
	int		save_in;
}				t_mini;

// utils
void	ft_disruptive_exit(char *exit_status, int exit_int);
void	ft_malloc_fail_check(void *status);
void	ft_strcpy(char *dst, char *src);
int		ft_strclen(char *str, char c);
int		ft_strslen(char *str, char *check);
char	*ft_strcdup(const char *s1, char c);
char	*ft_stradd(char *str1, char *str2); // in heredoc.c needs to be moved to an utils file
int		ft_strcmp(const char *s1, const char *s2);

// modules
int		ms_signals(void);
void	ms_line_executer(t_mini *data);
int		ms_lexer(t_list *tokens);
int		ms_heredoc(char *delimiter);
t_list	*ms_parser(t_list **tokens, t_mini *mini);

#endif
