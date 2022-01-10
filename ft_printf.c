/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:21:30 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/10 17:31:59 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_arg(char c, va_list list, int n)
{
	if (c == 'd' || c == 'i')
		return (ft_print_int(list, n));
	if (c == 'c')
		return (ft_print_char(list, n));
	if (c == 's')
		return (ft_print_str(list, n));
	if (c == 'x')
		return (ft_print_hex(list, n));
	if (c == 'X')
		return (ft_print_HEXA(list, n));
	if (c == 'p')
		return (ft_print_ptr(list, n));
	if (c == 'u')
		return (ft_print_uint(list, n));
	if (c == '%')
	{
		ft_putchar('%');
		return (n + 1);
	}
	return (1);
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

/*
int	main()
{
	char	*s;
	int		nb;
	//void	*ptr;

	nb = 1234;
	s = NULL;
	//ptr = &c;
	printf("\nn1 = %d\n", ft_printf("%s all\n", s));
	printf("\nn2 = %d\n", printf("This %p is even stranger", (void *)-2));
	//printf("r value = %p\n", ptr);
	//ft_printf("n value = %d\n", nb);
	return (0);
}
*/
