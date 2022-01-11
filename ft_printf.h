/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:29:33 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/11 15:23:16 by nverbrug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

//ft_printf.c
int		ft_check_arg(char c, va_list list, int n);
int		ft_printf(const char *fmt, ...);

//utils.c
void	ft_putchar(char c);
int 	ft_putstr(char *str, int n);
int		ft_strlen(char *str);
void	ft_putnbr_base(unsigned int arg, char *base, int *n);
void	ft_putpointer(unsigned long long value, char *base, int *n);

//args1.c
int		ft_print_char(va_list list, int n);
int		ft_print_str(va_list list, int n);
int		ft_print_ptr(va_list list, int n);
int		ft_print_hex(va_list list, int n);
int		ft_print_HEXA(va_list list, int n);

//args2.c
int		ft_print_int(va_list list, int n);
int		ft_print_uint(va_list list, int n);

#endif
