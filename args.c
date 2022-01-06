/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:56:06 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/05 11:05:20 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(char c, va_list list)
{
	if (c == 'd' || c == 'i')
		if (!ft_print_int(list))
			return (0);
	if (c == 'c')
		if (!ft_print_char(list))
			return (0);
	if (c == 's')
		if (!ft_print_str(list))
			return (0);
	if (c == '%')
		ft_putchar('%');
	if (c == 'x')
		if (!ft_print_hex(list))
			return (0);
	if (c == 'p')
		if (!ft_print_ptr(list))
			return (0);

	return (1);
}

int	ft_print_int(va_list list)
{
	int	arg;

	arg = va_arg(list, int);
	if (!arg)
		return (0);
	printf("%d\n", arg);
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
	int	arg;

	arg = va_arg(list, int);
	if (!arg)
		return (0);
	printf("%x\n", arg);
	return (1);
}

int	ft_print_ptr(va_list list)
{
	void	*arg;

	arg = va_arg(list, void *);
	if (!arg)
		return (0);
	printf("%s\n", arg);
	return (1);
}
