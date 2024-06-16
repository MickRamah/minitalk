# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 13:49:14 by zramahaz          #+#    #+#              #
#    Updated: 2024/06/16 14:34:19 by zramahaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
NAMEC_BONUS = client_bonus
NAMES_BONUS = server_bonus

FT_PRINTF = libftprintf.a

SRCC = client.c
SRCS = server.c
SRCC_BONUS = client_bonus.c
SRCS_BONUS = server_bonus.c

OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJC_BONUS = ${SRCC_BONUS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I include
RM = rm -rf

all: $(NAMEC) $(NAMES)

$(NAMEC): $(OBJC)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) ft_printf/$(FT_PRINTF) -o $(NAMEC)

$(NAMES): $(OBJS)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/$(FT_PRINTF) -o $(NAMES)

bonus : $(NAMEC_BONUS) $(NAMES_BONUS)

$(NAMEC_BONUS): $(OBJC_BONUS)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJC_BONUS) $(INCLUDE) ft_printf/$(FT_PRINTF) -o $(NAMEC_BONUS)

$(NAMES_BONUS): $(OBJS_BONUS)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCLUDE) ft_printf/$(FT_PRINTF) -o $(NAMES_BONUS)

clean:
	@make clean -C ft_printf
	${RM} $(OBJC)
	${RM} $(OBJS)
	${RM} $(OBJC_BONUS)
	${RM} $(OBJS_BONUS)

fclean: clean
	@make fclean -C ft_printf
	${RM} ${NAMEC}
	${RM} ${NAMES}
	${RM} ${NAMEC_BONUS}
	${RM} ${NAMES_BONUS}
	${RM} ${FT_PRINTF}

re: fclean all
