/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:51:59 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/10 14:21:16 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putstr(char *str, int n)
{
	while (*str)
	{
		ft_putchar(*str);
		n++;
		str++;
	}
	return (n);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(long value, char *base, int *n)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (value < 0)
	{
		value *= -1;
		ft_putchar('-');
		*n += 1;
	}
	if (value < len_base)
	{
		ft_putchar(base[value]);
		*n += 1;
	}
	else
	{
		ft_putnbr_base(value / len_base, base, n);
		ft_putnbr_base(value % len_base, base, n);
	}
}
