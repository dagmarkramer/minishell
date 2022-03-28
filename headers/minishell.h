#ifndef MINISHELL_H
# define MINISHELL_H

// #  include <stdlib.h>
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

typedef	struct s_keyval
{
	char	*key;
	char	*value;
}				t_keyval;

typedef struct s_mini
{
	char	**split;
	char	*ls;
	char	*options;
	char	*path;
	char	**path2d;
	char	*input;
	char	**splitin;
	char	**args;
	char 	**environ;
	t_list	*env;
}				t_mini;

// utils
void	ft_strcpy(char *dst, char *src);
int		ft_strclen(char *str, char c);
int		ft_strslen(char *str, char *check);
char	*ft_strcdup(const char *s1, char c);

void	ms_del_keyval(void *in);
t_list	*ms_init_env(char **environ);
char	*ms_getenv(char *key, t_list *envlst);


void	getpathoptions(char *prompt, t_mini *mini, char **newenv);
void	error_handling(char *errormessage);
int		ms_signals(void);
void	ft_execute(t_mini *mini, char **newenv);
void	ms_echo(t_mini *mini);
void	ms_pwd(t_mini *mini);
void	ms_cd(t_mini *mini);
void	ms_export(t_mini *mini);
void	ms_unset(t_mini *mini);
void	ms_env(t_mini *mini);
void	free2darr(t_mini *mini);
void    sort_alfa(t_list *env);

#endif