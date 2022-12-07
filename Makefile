# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 14:03:46 by zsyyida           #+#    #+#              #
#    Updated: 2022/11/23 15:28:33 by zsyyida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# so_longs executable
NAME = so_long

#make directories
INC_DIR = include
SRC_DIR = sources
OBJ_DIR = object
LIBFT_DIR = libft
# libft.a is the library so has .a at end
LIBFT = libft.a
MLX_DIR = mlx
MLX = libmlx.a

SRCS = error.c error_char_wall.c error_not_rectangle.c \
error_valid_path.c error_valid_path1.c main.c \
game_display_moves_close.c game_initialise.c game_movement.c game_open.c
#will add all object files into a directory one above
# %o: %c same as .c=.o
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC	= gcc
RM	= rm -rf
#-fsanitize=address can be added to cflags for debugging
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
#LFLAGS = -L $(MLX_DIR) -lmlx

#to create all of the .o files from files in SRC_DIR in OBJ_DIR
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIBFT_DIR)/$(INC_DIR) -I $(MLX_DIR) -c $< -o $@
#because the include directory for libft  is in libft.

all:	$(NAME)

# goes to file -L
# looks for library -l .All libraries have lib so ft
# this is especially important in linux. Even the order.
#"-c $< -o $@" is equivalent to "$(OBJ_SRC) -o pushswap"
# -C changes the path
$(NAME): $(OBJS)
	@make all -C $(MLX_DIR)
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX) $(OBJS) -Llibft -lft -o $(NAME)
	@printf "\x1b[31mso_long ready\\x1b[0m\n";

# -o turns object files into executable (coming after it)
# @make will go to and use libft makefile to make libft
#adding an @ before a command stops it from being printed

clean:
	$(RM) $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "object files removed"
#no fclean in minilibx
fclean: clean
	$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "object files and binary removed"

re:	fclean all
	@echo "object files and binary removed and binary remade"

# to remove all recipes that aren't files to avoid relinking
.PHONY:		all clean fclean re
