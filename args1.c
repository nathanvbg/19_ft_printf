/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:56:06 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/11 15:22:59 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list list, int n)
{
	int	arg;

	arg = va_arg(list, int);
	ft_putchar(arg);
	n++;
	return (n);
}

int	ft_print_str(va_list list, int n)
{
	char	*arg;

	arg = va_arg(list, char *);
	if (arg == NULL)
		n = ft_putstr("(null)", n);
	else
		n = ft_putstr(arg, n);
	return (n);
}

int	ft_print_hex(va_list list, int n)
{
	unsigned int	arg;

	arg = va_arg(list, unsigned int);
	ft_putnbr_base(arg, "0123456789abcdef", &n);
	return (n);
}

int	ft_print_HEXA(va_list list, int n)
{
	unsigned int	arg;

	arg = va_arg(list, unsigned int);
	ft_putnbr_base(arg, "0123456789ABCDEF", &n);
	return (n);
}

int	ft_print_ptr(va_list list, int n)
{
	void				*arg;
	unsigned long long	nb;

	arg = va_arg(list, void *);
	nb = (unsigned long long) arg;
	write(1, "0x", 2);
	n += 2;
	ft_putpointer(nb, "0123456789abcdef", &n);
	return (n);
}
