# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 16:32:21 by gchanet           #+#    #+#              #
#    Updated: 2021/11/02 07:15:47 by gchanet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BLU 		= \033[0;34m
GRN 		= \033[0;32m
RED 		= \033[0;31m
RST 		= \033[0m

OBLIG_SRC	= ft_printf.c
BONUS_SRC	= 
OBLIG_OBJ	= ${OBLIG_SRC:.c=.o}
BONUS_OBJ	= ${BONUS_SRC:.c=.o}

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I.
NAME		= libft.a

all: ${NAME}

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	@echo "${BLU}[BUILD]${RST} ${<:.c=.o}"

${NAME}: ${OBJ}
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "${GRN}[DONE]${RST} $(NAME) has created"

clean:
	@rm -f ${OBJ} ${OBJB}
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@rm -f ${NAME}
	@echo "${GRN}[FCLEAN]${RST} done"

bonus: ${NAME} ${OBJ} ${OBJB}
	@ar rcs $(NAME) $(OBJ) $(OBJB)
	@ranlib $(NAME)
	@echo "${GRN}[DONE]${RST} $(NAME) with bonus has created"

re: fclean all