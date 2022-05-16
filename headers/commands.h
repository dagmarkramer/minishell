/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:41:53 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/16 16:42:15 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "minishell.h"
# include <errno.h>

//	buildins
int		ms_cd(char **array, t_list *env);
void	ms_echo(char **array);
void	ms_env(t_mini *mini, char **array);
int		ms_exit(char **array, int last_return);
void	ms_export(t_mini *mini, char **array);
void	ms_pwd(char **array);
void	ms_unset(char **args, t_mini *mini);

// Utils
void	ft_printlst(t_list *lst, char *env);
int		ft_isallnotalpha(char *s);

#endif
