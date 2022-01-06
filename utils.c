/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:51:59 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/06 16:23:31 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(long value, char *base)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (value < 0)
	{
		value *= -1;
		ft_putchar('-');
	}
	if (value < len_base)
		ft_putchar(base[value]);
	else
	{
		ft_putnbr_base(value / len_base, base);
		ft_putnbr_base(value % len_base, base);
	}
}
