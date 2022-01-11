/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:51:59 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/11 15:23:46 by nverbrug         ###   ########.fr       */
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

void	ft_putnbr_base(unsigned int value, char *base, int *n)
{
	unsigned int	len_base;

	len_base = ft_strlen(base);
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

void	ft_putpointer(unsigned long long value, char *base, int *n)
{
	unsigned long long	len_base;

	len_base = ft_strlen(base);
	if (value < len_base)
	{
		ft_putchar(base[value]);
		*n += 1;
	}
	else
	{
		ft_putpointer(value / len_base, base, n);
		ft_putpointer(value % len_base, base, n);
	}
}
