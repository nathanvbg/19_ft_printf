/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:21:30 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/11 15:42:26 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(char c, va_list list, int n)
{
	if (c == 'd' || c == 'i')
		return (ft_print_int(list, n));
	else if (c == 'c')
		return (ft_print_char(list, n));
	else if (c == 's')
		return (ft_print_str(list, n));
	else if (c == 'x')
		return (ft_print_hex(list, n));
	else if (c == 'X')
		return (ft_print_HEXA(list, n));
	else if (c == 'p')
		return (ft_print_ptr(list, n));
	else if (c == 'u')
		return (ft_print_uint(list, n));
	else if (c == '%')
	{
		ft_putchar('%');
		return (n + 1);
	}
	else
		return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	list;
	int		i;
	int		n;

	i = 0;
	n = 0;
	va_start(list, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			n = ft_check_arg(fmt[i + 1], list, n);
			if (n < 0)
				return (-1);
			i += 2;
		}
		else
		{
			ft_putchar(fmt[i++]);
			n++;
		}
	}
	va_end(list);
	return (n);
}
