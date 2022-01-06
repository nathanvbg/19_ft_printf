/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:21:30 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/06 16:33:00 by naverbru         ###   ########.fr       */
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

int	ft_printf(const char *fmt, ...)
{
	va_list	list;
	int		i;

	i = 0;
	va_start(list, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			if (!ft_check_arg(fmt[i + 1], list))
				return (0);
			i += 2;
		}
		else
			ft_putchar(fmt[i++]);
	}
	va_end(list);
	return (1);
}

/*
int	main()
{
	char	c;
	int		nb;
	void	*ptr;

	nb = 1234;
	c = 'a';
	ptr = &c;
	//ft_printf("salut\n%d\n%s\n%c\n%%\n%p\n", 45, "hello", c, ptr);
	printf("r value = %p\n", ptr);
	ft_printf("n value = %d\n", nb);
	return (0);
}
*/
