/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:21:30 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/05 11:07:00 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
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
				break;
			i += 2;
		}
		else
			ft_putchar(fmt[i++]);
	}
	va_end(list);
	return (1);
}

int		main()
{
	char	c;
	void	*ptr;

	c = 'a';
	ptr = &c;
	ft_printf("salut\n%d\n%s\n%c\n%%\n%p\n", 45, "hello", c, ptr);
	return (0);
}
