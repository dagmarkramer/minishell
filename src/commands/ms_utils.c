#include "minishell.h"

void    ft_printlst(t_list *lst, char *env)
{
    while (lst)
    {
		if (!ft_strncmp("export", env, 1 + ft_strlen("export")))
		{
			printf("%s", "declare -x ");
        	printf("%s", (char *)((t_keyval *)lst->content)->key);
			printf("%s", "=\"");
        	printf("%s", (char *)((t_keyval *)lst->content)->value);
			printf("%s\n", "\"");
		}
		if (!ft_strncmp("env", env, ft_strlen("env")))
		{
			printf("%s", (char *)((t_keyval *)lst->content)->key);
			printf("%s", "=");
        	printf("%s\n", (char *)((t_keyval *)lst->content)->value);
		}
        lst = lst->next;
    }
}
