#include "minishell.h"
#include "libft.h"

void    sort_alfa(t_list *env)
{
    t_list  *lst1;
    t_list  *lst2;
    t_list  *temp;

    lst1 = env;
    temp = 0;
    while (lst1)
    {
        lst2 = lst1->next;
        while (lst2)
        {
            if (ft_strncmp(((t_keyval *)lst1->content)->key,
                ((t_keyval *)lst2->content)->key,
                ft_strlen(((t_keyval *)lst1->content)->key)) > 0)
            {
                temp = lst1->content;
                lst1->content = lst2->content;
                lst2->content = temp;
            }
            lst2 = lst2->next;
        }
        lst1 = lst1->next;
    }
}
