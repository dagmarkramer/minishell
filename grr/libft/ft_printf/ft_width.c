/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_width.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 20:49:17 by dkramer       #+#    #+#                 */
/*   Updated: 2021/03/07 10:43:38 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../libft.h"

void	ft_asteriskspace(const char *format, t_remember *z, va_list ap)
{
	if (format[z->i] == '*' && format[z->i] != '\0')
	{
		if (format[z->i + 1] != '*')
		{
			z->spaces = va_arg(ap, int);
			if (z->spaces < 0)
			{
				z->spaces = -z->spaces;
				z->left = 1;
			}
		}
		while (format[z->i + 1] == '*')
		{
			ft_putchar(format[z->i]);
			z->returnnr = z->returnnr + 2;
			z->i++;
		}
	}
}

void	ft_0flag(const char *format, t_remember *z)
{
	while (format[z->i] == '0')
	{
		z->dchange = 1;
		z->changedbefore = 1;
		z->schange = 1;
		z->i++;
	}
}

void	ft_getspaces(const char *format, t_remember *z)
{
	z->save = z->i;
	while (format[z->i] >= '0' && format[z->i] <= '9'
		&& format[z->i] != '\0')
	{
		z->i++;
		z->len++;
		if (!(format[z->i] >= '0' && format[z->i] <= '9')
			&& format[z->i] != '\0')
		{
			z->substr = ft_substr(format, z->save, z->len);
			if (!z->substr)
				return ;
			z->spaces = ft_atoi(z->substr);
			free(z->substr);
		}
	}
}

void	ft_widthconverter(const char *format, t_remember *z, va_list ap)
{
	while ((format[z->i] == '-' || (format[z->i] >= '0' && format[z->i]
				<= '9') || format[z->i] == '*') && format[z->i] != '\0')
	{
		if (format[z->i] == '-')
		{
			z->left = 1;
			z->i++;
		}
		if (((format[z->i] >= '0' && format[z->i] <= '9')
				|| format[z->i] == '*') && format[z->i] != '\0')
		{
			ft_0flag(format, z);
			if (format[z->i] >= '0' && format[z->i] <= '9'
				&& format[z->i] != '\0')
				ft_getspaces(format, z);
			ft_asteriskspace(format, z, ap);
		}
		if (((format[z->i] >= '0' && format[z->i] <= '9')
				|| format[z->i] == '*') && format[z->i] != '\0')
			z->i++;
	}
}

void	ft_conversions(const char *format, t_remember *z, va_list ap)
{
	if (format[z->i] == 'c' || format[z->i] == 's' || format[z->i] == 'd'
		|| format[z->i] == 'i' || format[z->i] == 'u' || format[z->i] == 'p'
		|| format[z->i] == 'x' || format[z->i] == 'X')
	{
		if (format[z->i] == 'c')
			ft_cformat(ap, z);
		if (format[z->i] == 's')
			ft_sformat(ap, z);
		if (format[z->i] == 'd' || format[z->i] == 'i' || format[z->i] == 'u')
		{
			ft_diuformat(format[z->i], ap, z);
			z->dchange = 0;
		}
		if (format[z->i] == 'p')
			ft_xformat(format[z->i], ap, z, "0123456789abcdef");
		if (format[z->i] == 'x')
			ft_xformat(format[z->i], ap, z, "0123456789abcdef");
		if (format[z->i] == 'X')
			ft_xformat(format[z->i], ap, z, "0123456789ABCDEF");
		z->i++;
		z->spaces = 0;
		z->maxminlen = 1;
		z->left = 0;
	}
}
