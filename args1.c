/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:56:06 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/10 17:42:07 by nverbrug         ###   ########.fr       */
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
	long			nb;

	arg = va_arg(list, unsigned int);
	nb = (long) arg;
	ft_putnbr_base(nb, "0123456789abcdef", &n);
	return (n);
}

int	ft_print_HEXA(va_list list, int n)
{
	unsigned int	arg;
	long			nb;

	arg = va_arg(list, unsigned int);
	nb = (long) arg;
	ft_putnbr_base(arg, "0123456789ABCDEF", &n);
	return (n);
}

int	ft_print_ptr(va_list list, int n)
{
	void	*arg;
	long	nb;

	arg = va_arg(list, void *);
	nb = (long) arg;
	write(1, "0x", 2);
	n += 2;
	ft_putnbr_base(nb, "0123456789abcdef", &n);
	return (n);
}
