/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_csformat.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkramer <dkramer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/09 15:02:07 by dkramer       #+#    #+#                 */
/*   Updated: 2021/03/07 10:43:38 by dkramer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "../libft.h"

void	ft_cformat(va_list ap, t_remember *z)
{
	char	c;

	while (z->spaces - 1 > 0 && z->left == 0)
	{
		ft_putchar(' ');
		z->returnnr++;
		z->spaces--;
	}
	c = va_arg(ap, int);
	ft_putchar(c);
	while (z->spaces - 1 > 0 && z->left == 1)
	{
		ft_putchar(' ');
		z->returnnr++;
		z->spaces--;
	}
	z->returnnr++;
}

void	ft_sohformat(t_remember *z, char *string)
{
	while (z->spaces - z->maxminlen + 1 > 0 && z->left == 0)
	{
		if (z->schange == 0)
			ft_putchar(' ');
		if (z->schange == 1)
			ft_putchar('0');
		z->spaces--;
		z->returnnr++;
	}
	while (z->counter < z->maxminlen - 1 && string[z->counter])
	{
		ft_putchar(string[z->counter]);
		z->returnnr++;
		z->counter++;
	}
	while (z->spaces - z->maxminlen + 1 > 0 && z->left == 1)
	{
		ft_putchar(' ');
		z->returnnr++;
		z->spaces--;
	}
	z->maxspecified = 0;
	z->counter = 0;
	z->negmaxlen = 0;
}

void	ft_sformat(va_list ap, t_remember *z)
{
	char	*string;

	string = va_arg(ap, char *);
	if (string)
		z->strlen = ft_strlen(string);
	else
	{
		z->strlen = 0;
		z->strlen = 6;
		string = "(null)";
	}
	if (z->maxminlen > z->strlen || z->negmaxlen == 1)
		z->maxminlen = z->strlen + 1;
	if (z->maxspecified == 0)
		z->maxminlen = z->strlen + 1;
	ft_sohformat(z, string);
}
