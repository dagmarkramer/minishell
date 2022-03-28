/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/03 13:34:08 by dkramer       #+#    #+#                 */
/*   Updated: 2021/01/12 20:45:45 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define FDMAX 10000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

int				get_next_line(int fd, char **line);

size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_intstrchr(const char *s, int mode);
char			*ft_strdup(const char *s1);

#endif
