/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:29:33 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/05 11:05:32 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

//utils.c
void	ft_putchar(char c);
void	ft_putstr(char *str);

//args.c
int		ft_check_arg(char c, va_list list);
int		ft_print_int(va_list list);
int		ft_print_char(va_list list);
int		ft_print_str(va_list list);
int		ft_print_ptr(va_list list);
int		ft_print_hex(va_list list);

#endif
