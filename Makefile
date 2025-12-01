# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 11:40:51 by tdharmar          #+#    #+#              #
#    Updated: 2025/12/01 12:47:17 by tdharmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	fdf

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror

INC_DIR			:=	includes/	
SRC_DIR			:=	srcs/

SRCS_FILES		:=	main.c

SRCS			:=	$(SRCS_FILES:%.c=$(SRC_DIR)%.c)
OBJS			:=	$(SRCS:%.c=%.o)

all: $(NAME) Makefile

$(NAME): $(OBJS) Makefile
	@make -C libft
	@cp libft/libft.a .
	${CC} ${CFLAGS} -I${INC_DIR} ${OBJS} libft.a -o $@

$(OBJS): %.o:%.c
	${CC} ${CFLAGS} -I${INC_DIR} -c $< -o $@

clean:
	rm -rf ${OBJS}
	@make -C libft clean

fclean: clean
	rm -f ${NAME}
	rm -rf libft.a
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re