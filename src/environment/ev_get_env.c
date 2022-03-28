#include "minishell.h"

char	*ev_getenv(char *key, t_list *envlst)
{
	t_keyval	*keyval;

	while (envlst != NULL)
	{
		keyval = (t_keyval *)envlst->content;
		if (ft_strncmp(key, keyval->key, 1 + ft_strlen(key)) == 0)
			return (keyval->value);
		envlst = envlst->next;
	}
	return (NULL);
}
