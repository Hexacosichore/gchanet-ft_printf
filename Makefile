# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 16:32:21 by gchanet           #+#    #+#              #
#    Updated: 2021/11/03 13:34:06 by gchanet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU 		= \033[0;34m
GRN 		= \033[0;32m
RED 		= \033[0;31m
RST 		= \033[0m

SRC			= ft_printf.c
OBJ			= ${SRC:.c=.o}

SRC_TESTER	= test.c
OBJ_TESTER	= ${SRC_TESTER:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
CLIBFT		= -L./libft/ -lft
NAME		= ft_printf

all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "${BLU}[BUILD]${RST} ${<:.c=.o}"

${NAME}: ${OBJ} ./includes/ft_printf.h
	@echo "${GRN}[DONE]${RST} $(NAME) has created"

clean:
	@rm -f ${OBJ} 
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@rm -f ${NAME}
	@echo "${GRN}[FCLEAN]${RST} done"

test: 
	@${CC} ${CFLAGS} -c *.c
	@${CC} ${CFLAGS} *.o -L ./libft -l ft -o ${NAME}
	@${CC} ${CFLAGS} ${OBJ} ${OBJ_TESTER} ${CLIBFT} -o tester
	@./tester

re: fclean all