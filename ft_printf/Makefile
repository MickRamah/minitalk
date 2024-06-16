# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zramahaz <zramahaz@student.42antanana      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/09 10:00:26 by zramahaz          #+#    #+#              #
#    Updated: 2024/03/14 12:52:46 by zramahaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c ft_printf.c ft_print_string.c \
	ft_print_int.c ft_print_ui.c ft_choice.c ft_print_address.c \
	ft_print_lower_hex.c ft_print_upper_hex.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJ)
	ar -rsc $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re
