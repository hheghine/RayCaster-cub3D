# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbalasan <hbalasan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 16:56:46 by hbalasan          #+#    #+#              #
#    Updated: 2023/11/29 21:29:36 by hbalasan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

PURPLE			:=	\033[0;34m
PINK			:=	\033[0;35m
RESET			:=	\033[0m

END				=	src/cub_end_macos.c

ifeq ($(shell uname -s), Linux)
	END = src/cub_end_linux.c
endif

SRC_DIR			=	src
SRCS			=	src/main.c src/cub_check.c src/cub_color.c src/cub_draw.c \
					src/cub_error.c src/cub_init.c src/cub_keys.c src/cub_map_check.c \
					src/cub_map_read.c src/cub_mlx.c src/cub_move.c src/cub_raycast.c \
					src/cub_texture.c src/cub_update.c src/cub_utils.c \
					src/get_next_line.c src/get_next_line_utils.c $(END)

HEADER			=	$(wildcard includes/*.h)
OBJ_DIR			=	obj
OBJS			=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
INCS			=	-I
CFLAGS			=	-fsanitize=address -g #-Wall -Wextra -Werror -

MINILIBX		=	./libraries/minilibx-macos
FMS				=	-L $(MINILIBX) -framework OpenGL -framework AppKit -lmlx -lm 

LIBFT			=	./libraries/libft/libft.a
LIBFT_PATH		=	./libraries/libft

PRINTF			=	printf

ifeq ($(shell uname -s), Linux)
	MINILIBX = ./libraries/minilibx-linux
	FMS = -L $(MINILIBX) -lmlx -lm -lX11 -lXext
endif

TOTAL_SRC		:= $(shell expr $(shell echo -n $(SRCS) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
#				ensures that division by zero errors are avoided when calculating the percentage of source files processed 
				ifeq ($(shell test $(TOTAL_SRC) -le 0; echo $$?),0)
					TOTAL_SRC := $(shell echo -n $(SRCS) | wc -w)
				endif
CURRENT_SRC		:= 0
SRC_PCT			= $(shell expr 100 \* $(CURRENT_SRC) / $(TOTAL_SRC))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile | $(OBJ_DIR)
	@$(eval CURRENT_SRC = $(shell expr $(CURRENT_SRC) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(PURPLE)$<$(RESET)..." "" $(CURRENT_SRC) $(TOTAL_SRC) $(SRC_PCT)
	@$(CC) $(CFLAGS) $(INCS)$(MINILIBX) -c $< -o $@

all:	mlx ${NAME}

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

mlx:
	@$(PRINTF) "$(PURPLE)Compiling Minilibx: "
	@make -C $(MINILIBX) > /dev/null 2>&1 & i=0; \
	while ps -p $$! > /dev/null; do \
		$(PRINTF) "$(PINK)✧$(RESET)"; \
		sleep 0.5; \
	done
	@echo "$(PURPLE) Minilibx compiled.$(RESET)"

${NAME}: $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FMS) -o ${NAME} > /dev/null 2>&1
	@$(PRINTF) "\r%100s\r$(PINK)✧ $(PURPLE)cub3D $(PINK)successfully compiled! ✧$(RESET)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(MINILIBX) > /dev/null 2>&1
	@$(PRINTF) "\r%100s\r$(PINK)✧ $(PURPLE)cub3D $(PINK)successfully cleaned! ✧$(RESET)\n"

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean mlx