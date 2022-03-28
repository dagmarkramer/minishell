#include "../headers/minishell.h"

// d

void	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
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
	while (ft_strchr(check, str[i]))
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