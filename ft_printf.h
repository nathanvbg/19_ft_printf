/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 09:29:33 by nverbrug          #+#    #+#             */
/*   Updated: 2022/01/06 16:22:15 by naverbru         ###   ########.fr       */
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
int		ft_strlen(char *str);
void	ft_putnbr_base(long arg, char *base);

//args.c
int		ft_check_arg(char c, va_list list);
int		ft_print_int(va_list list);
int		ft_print_char(va_list list);
int		ft_print_str(va_list list);
int		ft_print_ptr(va_list list);
int		ft_print_hex(va_list list);

#endif
