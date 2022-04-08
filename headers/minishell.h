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
#  include "lexer.h"

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
	int		pipes;
	int		tokens;
}				t_mini;

// utils
void	ft_disruptive_exit(char *exit_status, int exit_int);
void	ft_malloc_fail_check(void *status);
void	ft_strcpy(char *dst, char *src);
int		ft_strclen(char *str, char c);
int		ft_strslen(char *str, char *check);
char	*ft_strcdup(const char *s1, char c);


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

void    ft_printlst(t_list *lst, char *env);
int		ev_rem_env(char *key, t_list **envlst);

void	ms_line_executer(t_mini *data);
int		ms_lexer(t_list *tokens);
void    ft_printtokens(t_list *lst);
void    ft_printpipes(t_list *lst);
void	ms_count(t_list *tokens, t_mini *mini);
int	ms_parser(t_list **tokens, t_mini *mini);

#endif