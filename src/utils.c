#include "minishell.h"

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
			error_handling("malloc", mini);
		pathjoined = ft_strjoin(pathjoined, mini->ls);
		if (!pathjoined)
			error_handling("malloc", mini);
		execve(pathjoined, mini->args, newenv);
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
				error_handling("malloc", mini);
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
		error_handling("malloc", mini);
	mini->ls = ft_strdup(mini->split[0]);
	if (!mini->ls)
		error_handling("malloc", mini);
	mini->options = NULL;
	if (mini->split[1])
	{
		mini->options = ft_strdup(mini->split[1]);
		if (!mini->options)
			error_handling("malloc", mini);
	}
	free (mini->split[0]);
	free (mini->split[1]);
	free (mini->split);
	getpath(newenv, mini);
	mini->path2d = ft_split(mini->path, ':');
	free (mini->path);
	if (!mini->path2d)
		error_handling("malloc", mini);
}