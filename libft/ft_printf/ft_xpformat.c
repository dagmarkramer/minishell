/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_xpformat.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 15:02:07 by dkramer       #+#    #+#                 */
/*   Updated: 2021/03/07 10:43:38 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../libft.h"

void	ft_putwidth(t_remember *z, int mode)
{
	if (mode == 0)
	{
		if (z->dchange == 0)
			ft_putchar(' ');
		if (z->dchange == 1)
		{
			if (z->negative == 1)
			{
				ft_putchar('-');
				z->negative = 0;
			}
			ft_putchar('0');
		}
		z->spaces--;
		z->returnnr++;
	}
	if (mode == 1)
	{
		ft_putchar(' ');
		z->spaces--;
		z->returnnr++;
	}
}

void	ft_x3format(char c, t_remember *z)
{
	if (c == 'p' && z->maxspecified == 1)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
	if (!z->keep && c == 'p')
		z->returnnr = z->returnnr + 2;
	ft_zeros(z);
	if (c == 'p' && z->maxspecified == 0)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
}

void	ft_x4format(char c, t_remember *z, char *base)
{
	if (z->digits + 1 > z->maxminlen && c == 'p')
		z->maxminlen = z->digits + 1;
	while (z->spaces - z->maxminlen - 1 > 0 && z->left == 0 && c == 'p')
		ft_putwidth(z, 0);
	while (z->spaces - z->digits - z->characters > 0 && z->left == 0
		&& c != 'p')
		ft_putwidth(z, 0);
	ft_x3format(c, z);
	if (z->keep == -2147483648)
		ft_putstr_fd("2147483648", 1);
	else if (z->keep == 4294967295u)
	{
		if (c == 'x' || c == 'p')
			ft_putstr_fd("ffffffff", 1);
		if (c == 'X')
			ft_putstr_fd("FFFFFFFF", 1);
	}
	else if (!(z->keep == 0 && z->checkifnrisnull == 1))
	{
		z->strnr = ft_itoa_base(z->keep, base);
		if (!z->strnr)
			return ;
		ft_putstr_fd(z->strnr, 1);
		free(z->strnr);
	}
}

void	ft_xformat(char c, va_list ap, t_remember *z, char *base)
{
	int	temp;

	z->characters = 0;
	z->negative = 0;
	if (c == 'x' || c == 'X')
		z->keep = va_arg(ap, unsigned int);
	if (c == 'p')
		z->keep = (long long)va_arg(ap, void **);
	ft_x2format(c, z);
	z->zeros = z->maxminlen - 1 - z->digits;
	temp = z->zeros;
	while (temp > 0)
	{
		z->digits++;
		temp--;
	}
	ft_x4format(c, z, base);
	while (z->spaces - z->maxminlen - 1 > 0 && z->left == 1 && c == 'p')
		ft_putwidth(z, 1);
	while (z->spaces - z->digits - z->characters > 0 && z->left == 1
		&& c != 'p')
		ft_putwidth(z, 1);
}

void	ft_x2format(char c, t_remember *z)
{
	if (z->keep < 0)
	{
		z->negative = 1;
		if (z->keep != -2147483648)
			z->keep = -z->keep;
		z->returnnr++;
		z->characters++;
	}
	z->digits = ft_nrofdigits(z->keep, 16);
	if (c == 'p' && z->keep)
		z->returnnr = z->returnnr + 2;
	if (z->keep == -2147483648)
		z->digits--;
	z->returnnr = z->returnnr + z->digits;
	if (z->keep == 0 && z->checkifnrisnull == 1)
	{
		z->returnnr--;
		z->digits = 0;
	}
}
