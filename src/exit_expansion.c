/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_expansion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/14 14:14:49 by dkramer       #+#    #+#                 */
/*   Updated: 2022/05/16 16:41:45 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstringtostderror(char *s1, char *s2)
{
	char	*s;

	s = ft_strjoin(s1, s2);
	ft_malloc_fail_check(s);
	ft_putendl_fd(s, 2);
}

void	fillnewinput(t_mini *data, char *exitstatus, char **newinput, int c)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (data->input[i])
	{
		if (data->input[i] == '$' && data->input[i + 1] == '?')
		{
			while (exitstatus[c])
			{
				(*newinput)[a] = exitstatus[c];
				a++;
				c++;
			}
			c = 0;
			i += 2;
		}
		(*newinput)[a] = data->input[i];
		if ((*newinput)[a])
			a++;
		if (data->input[i])
			i++;
	}
	(*newinput)[a] = '\0';
}

int	count_exit_status(char *input)
{
	int	i;
	int	exits;

	i = 0;
	exits = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] == '?')
		{
			exits++;
			i += 2;
		}
		if (input[i])
			i++;
	}
	return (exits);
}

void	replaceexitstatus(t_mini *data)
{
	char	*newinput;
	char	*exitstatus;
	int		nr_exits;

	nr_exits = count_exit_status(data->input);
	exitstatus = ft_itoa(data->last_return);
	ft_malloc_fail_check(exitstatus);
	newinput = malloc(sizeof(char) * (ft_strlen(data->input) - 2
				+ nr_exits * (ft_strlen(exitstatus)) + 1));
	ft_malloc_fail_check(newinput);
	fillnewinput(data, exitstatus, &newinput, 0);
	free (data->input);
	free (exitstatus);
	data->input = newinput;
}
