# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdharmar <tdharmar@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 11:40:51 by tdharmar          #+#    #+#              #
#    Updated: 2025/12/01 22:15:14 by tdharmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	fdf

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror

LDFLAGS			:=	-ldl -lglfw -pthread -lm

INC_DIR			:=	includes/	
SRC_DIR			:=	srcs/

SRCS_FILES		:=	main.c

SRCS			:=	$(SRCS_FILES:%.c=$(SRC_DIR)%.c)
OBJS			:=	$(SRCS:%.c=%.o)

MLX42_DIR		:=	MLX42/
MLX42_INC_DIR	:=	$(MLX42_DIR)/include/
MLX42			:=	libmlx42.a


all: $(NAME) Makefile

$(NAME): $(OBJS) Makefile $(MLX42)
	@make -C libft
	@cp libft/libft.a .
	${CC} ${CFLAGS} ${OBJS} libft.a ${MLX42} ${LDFLAGS} -o $@

$(OBJS): %.o:%.c
	${CC} ${CFLAGS} -I${INC_DIR} -I ${MLX42_INC_DIR} -c $< -o $@

mlx				:	$(MLX42)

$(MLX42)        :   $(MLX42_DIR)
	@# Fix shebang for NixOS/Linux compatibility
	@sed -i 's|^#!/bin/bash|#!/usr/bin/env bash|' $(MLX42_DIR)/tools/compile_shader.sh
	@# Clean any previous cmake build to prevent cache errors
	@rm -rf $(MLX42_DIR)/build
	@# Configure and build - FORCE include path for NixOS/GCC14 compatibility
	@cd $(MLX42_DIR) && cmake -B build -DCMAKE_C_FLAGS="-I$(CURDIR)/$(MLX42_DIR)/include"
	@cd $(MLX42_DIR) && cmake --build build -j4
	@cp $(MLX42_DIR)/build/$(MLX42) .

$(MLX42_DIR)	:
	@git clone https://github.com/codam-coding-college/MLX42.git ${MLX42_DIR}


clean:
	rm -rf ${OBJS}
	@make -C libft clean

fclean: clean
	rm -f ${NAME}
	rm -rf libft.a $(MLX42)
	rm -rf $(MLX42_DIR)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re mlx