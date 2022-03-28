#ifndef MS_ENVIRON_H
# define MS_ENVIRON_H

int		ev_add_env(char *key, char *value, t_list **envlst);
char	*ev_getenv(char *key, t_list *envlst);
t_list	*ev_init_env(char **environ);
void	ev_del_keyval(void *in);
t_list	*ev_keyval_lst_add(char *key, char *value);
void    ev_sort_alfa(t_list *env);

#endif