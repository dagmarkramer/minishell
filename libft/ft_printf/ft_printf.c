/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/17 14:03:01 by dkramer       #+#    #+#                 */
/*   Updated: 2021/03/07 10:42:46 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include "libftprintf.h"

void	ft_initializevariables(t_remember *z)
{
	z->len = 0;
	z->spaces = 0;
	z->left = 0;
	z->maxminlen = 1;
	z->dchange = 0;
	z->counter = 0;
	z->schange = 0;
	z->checkifnrisnull = 0;
	z->returnnr = 0;
	z->negative = 0;
	z->maxspecified = 0;
	z->negmaxlen = 0;
	z->changedbefore = 0;
	z->i = 0;
}

int	ft_printf(const char *format, ...)
{
	t_remember	z;
	va_list		ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	ft_initializevariables(&z);
	while (format[z.i])
	{
		while (format[z.i] != '%' && format[z.i] != '\0')
		{
			ft_putchar(format[z.i]);
			z.returnnr++;
			z.i++;
		}
		ft_convertloop(format, &z, ap);
		if (format[z.i] == '%' && format[z.i] != '\0')
		{
			ft_putchar(format[z.i]);
			z.returnnr++;
			z.i = z.i + 2;
		}
	}
	va_end(ap);
	return (z.returnnr);
}
