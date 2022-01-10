/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:28:16 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/10 16:57:55 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uint(va_list list, int n)
{
	unsigned int arg;
	long	nb;

	arg = va_arg(list, unsigned int);
	nb = (long) arg;
	ft_putnbr_base(nb, "0123456789", &n);
	return (n);
}

int	ft_print_int(va_list list, int n)
{
	int		arg;
	long	nb;

	arg = va_arg(list, int);
	nb = (long) arg;
	ft_putnbr_base(nb, "0123456789", &n);
	return (n);
}
