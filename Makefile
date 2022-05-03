# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrebelo- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 10:51:29 by jrebelo-          #+#    #+#              #
#    Updated: 2022/02/16 15:11:18 by jrebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c ft_putnbr_base.c ft_printf_utils.c

OBJS		= 		$(SRCS:.c=.o)

BONUS_SRCS	= 		

BONUS_OBJS	= 		$(BONUS_SRCS:.c=.o)

CC		=	gcc

CFLAGS		= 	-Wall -Wextra -Werror

LIB		= 	ar rcs

RM		=	/bin/rm -f

NAME		= 	libftprintf.a


INCLUDE		= 		ft_printf.h

all		:		$(NAME)

$(NAME)		:		$(OBJS)
				$(MAKE) bonus -C ./libft
				cp libft/libft.a $(NAME)
				$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
				ar -rcs $(NAME) $(OBJS)

bonus		:		$(NAME) $(BONUS_OBJS)
					$(LIB) $(NAME) $(BONUS_OBJS)

.c.o		:
					$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean		:
					$(RM) $(OBJS) $(BONUS_OBJS)

fclean		:		clean
						$(RM) $(NAME)

re			:		fclean all

rebonus		:		fclean bonus

.PHONY		:		all clean fclean re bonus rebonus
