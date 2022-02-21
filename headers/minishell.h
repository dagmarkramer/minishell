#ifndef MINISHELL_H
# define MINISHELL_H

// #  include <stdlib.h>
#  include <stdio.h>
#  include <readline/readline.h>
#  include <readline/history.h>
#  include <stdlib.h>
#  include "../Libft/libft.h"
#  include <fcntl.h>
#  include <limits.h>
#  include <dirent.h>

typedef struct s_mini
{
	char	**split;
	char	*ls;
	char	*options;
	char	*path;
	char	**path2d;
	char	*prompt;
	char	**splitin;
	char	**args;
}				t_mini;

void	getpathoptions(char *prompt, t_mini *mini, char **newenv);
void	error_handling(char *errormessage);
int		signals(void);
void	ft_execute(t_mini *mini, char **newenv);
void	ms_echo(t_mini *mini);
void	ms_pwd(t_mini *mini);
void	ms_cd(t_mini *mini);
void	ms_export(t_mini *mini);
void	ms_unset(t_mini *mini);
void	ms_env(t_mini *mini);
void	ms_exit(t_mini *mini);

#endif