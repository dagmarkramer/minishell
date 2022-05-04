#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"

//	buildins
void	ms_cd(char **array);
void	ms_echo(char **array);
void	ms_env(t_mini *mini, char **array);
void	ms_exit(char **array);
void	ms_export(t_mini *mini, char **array);
void	ms_pwd(char **array);
void	ms_unset(char **args, t_mini *mini);

// Utils
void    ft_printlst(t_list *lst, char *env);

#endif
