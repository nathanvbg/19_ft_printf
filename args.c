/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:56:06 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/06 16:28:18 by naverbru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list list)
{
	long	arg;

	arg = va_arg(list, int);
	if (!arg)
		return (0);
	ft_putnbr_base(arg, "0123456789");
	return (1);
}

int	ft_print_char(va_list list)
{
	int	arg;

	arg = va_arg(list, int);
	if (!arg)
		return (0);
	ft_putchar(arg);
	return (1);
}

int	ft_print_str(va_list list)
{
	char	*arg;

	arg = va_arg(list, char *);
	if (!arg)
		return (0);
	printf("%s\n", arg);
	return (1);
}

int	ft_print_hex(va_list list)
{
	long	arg;

	arg = va_arg(list, int);
	if (!arg)
		return (0);
	ft_putnbr_base(arg, "0123456789abcdef");
	return (1);
}

int	ft_print_ptr(va_list list)
{
	long	arg;

	arg = va_arg(list, long);
	if (!arg)
		return (0);
	write(1, "0x", 2);
	ft_putnbr_base(arg, "0123456789abcdef");
	return (1);
}
