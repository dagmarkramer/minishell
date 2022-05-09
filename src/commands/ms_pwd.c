/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ms_pwd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/09 22:48:05 by oswin         #+#    #+#                 */
/*   Updated: 2022/05/09 22:48:06 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_pwd(char **array)
{
	char	buf[PATH_MAX];

	if (ft_strncmp(array[0], "pwd", 4) != 0)
		return ;
	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
}
