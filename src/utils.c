#include "minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	return(ft_strncmp(s1, s2, 1 + (size_t)ft_strlen(s2)));
}

// used in ms_env
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

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	ft_strclen(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_strslen(char *str, char *check)
{
	int i;

	i = 0;
	while (ft_strchr(check, str[i]) == 0 && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcdup(const char *s1, char c)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(*s1) * (ft_strclen((char *)s1, c) + 1));
	if (copy == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0' && s1[i] != c)
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_disruptive_exit(char *exit_status, int exit_int)
{
	ft_putendl_fd(exit_status, 2);
	exit(exit_int);
}

void	ft_malloc_fail_check(void *status)
{
	if (status == NULL)
		ft_disruptive_exit("malloc fail", 333);
}
