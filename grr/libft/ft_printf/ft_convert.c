/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_convert.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/19 09:36:21 by dkramer       #+#    #+#                 */
/*   Updated: 2021/03/07 10:43:36 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../libft.h"

void	ft_asteriskprc(t_remember *z, va_list ap)
{
	z->remember = va_arg(ap, int);
	if (z->remember >= 0)
		z->maxminlen = z->remember + 1;
	if (z->remember < 0)
	{
		if (z->changedbefore == 1)
			z->dchange = 1;
		z->maxminlen = 2;
		z->negmaxlen = 1;
	}
	if (z->remember == 0)
		z->checkifnrisnull = 1;
	z->i++;
}

void	ft_prc(const char *format, t_remember *z)
{
	while (format[z->i] >= '0' && format[z->i] <= '9')
	{
		z->len++;
		z->i++;
		if (!(format[z->i] >= '0' && format[z->i] <= '9'))
		{
			z->substr = ft_substr(format, z->save, z->len);
			if (!z->substr)
				return ;
			z->maxminlen = ft_atoi(z->substr) + 1;
			if (!ft_atoi(z->substr))
				z->checkifnrisnull = 1;
			free(z->substr);
		}
	}
}

void	ft_prcconverter(const char *format, t_remember *z, va_list ap)
{
	z->i++;
	z->dchange = 0;
	z->maxspecified = 1;
	if (format[z->i] >= '0' && format[z->i] <= '9' && format[z->i] != '\0')
	{
		z->save = z->i;
		ft_prc(format, z);
	}
	else if (format[z->i] == '*' && format[z->i] != '\0')
		ft_asteriskprc(z, ap);
	else if (format[z->i] != '\0')
	{
		z->maxminlen = 1;
		z->checkifnrisnull = 1;
	}
}

int	ft_formatchecker(const char *format, t_remember *z)
{
	while (format[z->i] != '-' && !(format[z->i] >= '0' && format[z->i] <= '9')
		&& format[z->i] != '*' && format[z->i] != '.' && format[z->i] != 'c'
		&& format[z->i] != 's' && format[z->i] != 'p' && format[z->i] != 'i'
		&& format[z->i] != 'u' && format[z->i] != 'd' && format[z->i] != 'x'
		&& format[z->i] != 'X' && format[z->i] != '\0')
		return (1);
	return (0);
}

void	ft_convertloop(const char *format, t_remember *z, va_list ap)
{
	while (format[z->i] == '%' && format[z->i + 1] != '%'
		&& format[z->i] != '\0')
	{
		z->i++;
		if (format[z->i] == 0)
			ft_diuformat('%', ap, z);
		if (ft_formatchecker(format, z))
		{
			ft_putchar(format[z->i]);
			z->returnnr++;
			z->i++;
		}
		while (ft_formatchecker(format, z))
			z->i++;
		ft_widthconverter(format, z, ap);
		if (format[z->i] == '.' && format[z->i] != '\0')
		{
			ft_prcconverter(format, z, ap);
		}
		ft_conversions(format, z, ap);
	}
}
