# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nverbrug <nverbrug@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:47:35 by nverbrug          #+#    #+#              #
#    Updated: 2022/01/10 13:32:51 by nverbrug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= args1.c args2.c ft_printf.c utils.c
OBJS	= ${SRCS:.c=.o}
INCS	= ft_printf.h
NAME	= libftprintf.a
LIBC	= ar rc
LIBR	= ranlib
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]

.PHONY: all clean fclean re .c.o norm

