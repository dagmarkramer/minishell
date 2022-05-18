/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_environ.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:42:37 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/18 16:35:00 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ENVIRON_H
# define MS_ENVIRON_H

// interact with our envlst
char	*ev_getenv(char *key, t_list *envlst);
int		ev_rem_env(char *key, t_list **env);
int		ev_add_env(char *key, char *value, t_list **envlst);
int		ev_change_env(char *key, char *value, t_list **envlst);

// utility functions used under the hood in envlst and used for init
t_list	*ev_init_env(char **environ);
void	ev_del_keyval(void *in);
t_list	*ev_keyval_lst_add(char *key, char *value);
void	ev_sort_alfa(t_list *env);

#endif