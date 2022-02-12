/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 09:45:09 by dkramer       #+#    #+#                 */
/*   Updated: 2021/03/03 11:17:59 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_remember
{
	char				*string;
	int					save;
	int					len;
	int					spaces;
	int					left;
	int					maxminlen;
	long long			keep;
	int					zeros;
	int					dchange;
	char				savechar;
	int					digits;
	unsigned long long	pointeraddress;
	int					checkifnrisnull;
	int					returnnr;
	int					negative;
	int					characters;
	int					remember;
	int					strlen;
	int					maxspecified;
	int					checkifd;
	int					schange;
	int					negmaxlen;
	char				*strwithout0x;
	int					changedbefore;
	int					counter;
	unsigned int		i;
	char				*substr;
	char				*strnr;
}				t_remember;

int				ft_printf(const char *format, ...);
void			ft_cformat(va_list ap, t_remember *z);
void			ft_sformat(va_list ap, t_remember *z);
void			ft_sohformat(t_remember *z, char *string);
void			ft_diuformat(char c, va_list ap, t_remember *z);
void			ft_diu2format(char c, t_remember *z);
void			ft_zeros(t_remember *z);
void			ft_xformat(char c, va_list ap, t_remember *z, char *base);
void			ft_x2format(char c, t_remember *z);
void			ft_x4format(char c, t_remember *z, char *base);
void			ft_putwidth(t_remember *z, int mode);
void			ft_initializevariables(t_remember *z);
void			ft_widthconverter(const char *format, t_remember *z,
					va_list ap);
void			ft_asteriskspace(const char *format, t_remember *z, va_list ap);
void			ft_0flag(const char *format, t_remember *z);
void			ft_convertloop(const char *format, t_remember *z, va_list ap);
void			ft_conversions(const char *format, t_remember *z, va_list ap);
void			ft_asteriskprc(t_remember *z, va_list ap);
void			ft_prcconverter(const char *format, t_remember *z, va_list ap);
void			ft_prc(const char *format, t_remember *z);
int				ft_formatchecker(const char *format, t_remember *z);
void			ft_getspaces(const char *format, t_remember *z);

#endif
