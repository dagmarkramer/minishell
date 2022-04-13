#include "minishell.h"

void	ft_print2darr(char **array)
{
	int	i;

	i = 0;
	printf("%s\n", "start");
	while (array && array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	printf("%s\n", "end");
}

void	free2darr(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->splitin[i])
	{
		free (mini->splitin[i]);
		i++;
	}
	free (mini->splitin);
}

// this is a real free 2d array!
// void	free2darr(void **arrays)
// {
// 	int	i;

// 	i = 0;
// 	while (arrays[i])
// 	{
// 		free (arrays[i]);
// 		i++;
// 	}
// 	free (arrays);
// }

void    ft_printpipes(t_list *lst)
{
	int i = 0;
	int	a = 0;
    while (lst)
    {
		// if (!ft_strncmp("export", env, ft_strlen("export")))
		// {
			// printf("%s", "declare -x ");
		// if 
		bool yes;
		yes = true;
		printf("yes = %d\n", yes);
        printf("before , %d = %d\n", i, (int)((t_pipe *)lst->content)->pipe_before);
        printf("after  , %d = %d\n", i, (int)((t_pipe *)lst->content)->pipe_after);
		while((char *)((t_pipe *)lst->content)->tokens[a])
		{
			printf("token , %s \n", (char *)((t_pipe *)lst->content)->tokens[a]);
			a++;
		}
		a = 0;
		i++;
			// printf("%s", "=\"");
        	// printf("%s", (char *)((t_keyval *)lst->content)->value);
			// printf("%s\n", "\"");
		// }
		// if (!ft_strncmp("env", env, ft_strlen("env")))
		// {
		// 	printf("%s", (char *)((t_keyval *)lst->content)->key);
		// 	printf("%s", "=");
        // 	printf("%s\n", (char *)((t_keyval *)lst->content)->value);
		// }
        lst = lst->next;
    }
}

void    ft_printtokens(t_list *lst)
{
    while (lst)
    {
		// if (!ft_strncmp("export", env, ft_strlen("export")))
		// {
			// printf("%s", "declare -x ");
		// if 
        printf("%d\n", ((t_token *)lst->content)->id);
			// printf("%s", "=\"");
        	// printf("%s", (char *)((t_keyval *)lst->content)->value);
			// printf("%s\n", "\"");
		// }
		// if (!ft_strncmp("env", env, ft_strlen("env")))
		// {
		// 	printf("%s", (char *)((t_keyval *)lst->content)->key);
		// 	printf("%s", "=");
        // 	printf("%s\n", (char *)((t_keyval *)lst->content)->value);
		// }
        lst = lst->next;
    }
}

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

void	error_handling(char *errormessage)
{
	perror(errormessage);
}

void	perror_handling(char *err_msg)
{
	error_handling(err_msg);
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

void	ft_execute(t_mini *mini, char **newenv)
{
	int		i;
	char	*pathjoined;

	i = -1;
	while (mini->path2d[i + 1])
	{
		i++;
		pathjoined = ft_strjoin(mini->path2d[i], "/");
		if (!pathjoined)
			error_handling("malloc");
		pathjoined = ft_strjoin(pathjoined, mini->ls);
		if (!pathjoined)
			error_handling("malloc");
		execve(pathjoined, &mini->input, newenv);
	}
	exit (127);
}

void	getpath(char **newenv, t_mini *mini)
{
	int		i;

	i = 0;
	while (newenv[i])
	{
		if (ft_strnstr(newenv[i], "PATH=", ft_strlen(newenv[i])))
		{
			mini->split = ft_split(newenv[i], '=');
			if (!mini->split)
				error_handling("malloc");
			mini->path = ft_strdup(mini->split[1]);
		}
		i++;
	}
	free (mini->split[0]);
	free (mini->split[1]);
	free (mini->split);
}

void	getpathoptions(char *prompt, t_mini *mini, char **newenv)
{
	mini->split = ft_split(prompt, ' ');
	if (!mini->split)
		error_handling("malloc");
	mini->ls = ft_strdup(mini->split[0]);
	if (!mini->ls)
		error_handling("malloc");
	mini->options = NULL;
	if (mini->split[1])
	{
		mini->options = ft_strdup(mini->split[1]);
		if (!mini->options)
			error_handling("malloc");
	}
	free (mini->split[0]);
	free (mini->split[1]);
	free (mini->split);
	getpath(newenv, mini);
	mini->path2d = ft_split(mini->path, ':');
	free (mini->path);
	if (!mini->path2d)
		error_handling("malloc");
}

// this is in here for savekeeping in case we need it later
// void	ms_next(t_mini *mini)
// {
// 	//return error check
// 	if (!ft_strncmp(mini->input, "env", ft_strlen("env"))) // plus 1? for null terminator '\0'
// 		ms_env(mini);
// 	if (!ft_strncmp(mini->input, "export", ft_strlen("export")))
// 		ms_export(mini);
// 	if (!ft_strncmp(mini->input, "unset", ft_strlen("unset")))
// 		ms_unset(mini);
// 	// if (!ft_strncmp(mini->input, "echo", ft_strlen("echo")))
// 	// 	ms_echo(mini);
// 	if (!ft_strncmp(mini->input, "pwd", ft_strlen("pwd")))
// 		ms_pwd(mini);
// 	if (!ft_strncmp(mini->input, "cd", ft_strlen("cd")))
// 		ms_cd(mini);
// 	// if (!ft_strncmp(mini->splitin[0], "<", ft_strlen(mini->splitin[0])))
// 	// 	ms_redirect(mini, "<");
// 	// if (!ft_strncmp(mini->splitin[0], ">", ft_strlen(mini->splitin[0])))
// 	// 	ms_redirect(mini, ">");
// 	// if (!ft_strncmp(mini->splitin[0], ">>", ft_strlen(mini->splitin[0])))
// 	// 	ms_redirect(mini, ">>");
// }
