/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_diuformat.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 13:51:05 by dkramer       #+#    #+#                 */
/*   Updated: 2021/03/07 10:43:38 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../libft.h"

void	ft_zeros(t_remember *z)
{
	if (z->negative == 1)
		ft_putchar('-');
	while (z->zeros > 0)
	{
		ft_putchar('0');
		z->returnnr++;
		z->zeros--;
	}
}

void	ft_diu2format(char c, t_remember *z)
{
	int	temp;

	z->zeros = z->maxminlen - 1 - z->digits;
	temp = z->zeros;
	while (temp > 0)
	{
		z->digits++;
		temp--;
	}
	while (z->spaces - z->digits - z->characters > 0 && z->left == 0)
		ft_putwidth(z, 0);
	ft_zeros(z);
	if (z->keep == -2147483648)
		ft_putstr_fd("2147483648", 1);
	else if (z->keep == 4294967295)
		ft_putstr_fd("4294967295", 1);
	else if (c == '%')
		ft_putchar('%');
	else if (!(z->keep == 0 && z->checkifnrisnull == 1))
		ft_putnbr_fd(z->keep, 1);
	else if (z->maxminlen && !(z->keep == 0 && z->checkifnrisnull == 1))
		ft_putnbr_fd(z->keep, 1);
	while (z->spaces - z->digits - z->characters > 0 && z->left == 1)
		ft_putwidth(z, 1);
}

void	ft_diuformat(char c, va_list ap, t_remember *z)
{
	z->characters = 0;
	z->negative = 0;
	if (c == 'd' || c == 'i')
		z->keep = va_arg(ap, int);
	if (c == 'u')
		z->keep = va_arg(ap, unsigned int);
	if (c == '%')
		z->keep = 0;
	if (z->keep < 0)
	{
		z->negative = 1;
		if (z->keep != -2147483648)
			z->keep = -z->keep;
		z->returnnr++;
		z->characters++;
	}
	z->digits = ft_nrofdigits(z->keep, 10);
	if (z->keep == -2147483648)
		z->digits--;
	if (!(z->keep == 0 && z->checkifnrisnull == 1))
		z->returnnr = z->returnnr + z->digits;
	if (z->keep == 0 && z->checkifnrisnull == 1)
		z->digits = 0;
	ft_diu2format(c, z);
}
