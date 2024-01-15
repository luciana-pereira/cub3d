NAME 		= cub3D
NAME_BONUS	= cub3D_bonus

LIBFT_PATH	= ./lib/libft
LIBFT		= $(LIBFT_PATH)/libft.a

MLX_PATH	= ./lib/minilibx-linux
MLX			= $(MLX_PATH)/libmlx.a

INCLUDE =	-I ../../include -I $(LIBFT_PATH)

SRC_FILES		=	mandatory/src/events/key_events.c					\
					mandatory/src/events/movement.c		    			\
					mandatory/src/graphics/render_walls.c				\
					mandatory/src/graphics/drawing.c					\
					mandatory/src/graphics/load_textures.c				\
					mandatory/src/graphics/rendering.c	  				\
					mandatory/src/init/init_game.c	        			\
					mandatory/src/init/init_graph_env.c	      			\
					mandatory/src/init/init_map.c	        			\
					mandatory/src/init/init_mlx.c	        			\
					mandatory/src/init/init_player.c	      			\
					mandatory/src/init/init_setup.c	        			\
					mandatory/src/math/calculate.c						\
					mandatory/src/math/flood_fill.c						\
					mandatory/src/math/math_oper.c						\
					mandatory/src/parse/colors.c						\
					mandatory/src/parse/file_processing.c	     		\
					mandatory/src/parse/map_allocation.c				\
					mandatory/src/parse/map_operations.c				\
					mandatory/src/parse/map_processing.c				\
					mandatory/src/parse/map_valid_config.c	    		\
					mandatory/src/parse/map_validation.c				\
					mandatory/src/parse/map_verification.c				\
					mandatory/src/parse/process_elements.c				\
					mandatory/src/parse/process_input.c  				\
					mandatory/src/parse/textures.c						\
					mandatory/src/rays/ray_casting.c   					\
					mandatory/src/rays/ray_intercept.c					\
					mandatory/src/rays/ray_processing.c	 				\
					mandatory/src/utils/errors.c						\
					mandatory/src/utils/free_array.c	 				\
					mandatory/src/utils/free_map.c	    				\
					mandatory/src/utils/free_struct.c	 				\
					mandatory/src/utils/utils.c	    				    \
					mandatory/src/main.c								\


CC = cc
RM = -rm -f
RM_DIR = rm -rf

OBJ_DIR	  = ./mandatory/obj
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

OBJ_DIR_BONUS	= ./bonus/obj
OBJ_FILES_BONUS = $(SRC_FILES_BONUS:%.c=$(OBJ_DIR_BONUS)/%.o)

HEADER_FILES	=	mandatory/includes/cub3d.h			\
					mandatory/includes/buttons.h		\
					mandatory/includes/structs.h		\
					mandatory/includes/colors.h			\
					mandatory/includes/constants.h		\
					mandatory/includes/errors.h			\
					mandatory/includes/functions.h		\

HEADER_FILES_BONUS	=	bonus/includes/cub3d_bonus.h	\
						bonus/includes/buttons_bonus.h	\
						bonus/includes/structs_bonus.h	\
						bonus/includes/colors_bonus.h	\
						bonus/includes/constants_bonus.h\
						bonus/includes/errors_bonus.h	\
						bonus/includes/functions_bonus.h\

CFLAGS = -Wall -Werror -Wextra -g3
MLXFLAGS = -lm -lXext -lX11

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_PATH) --no-print-directory

$(MLX):
	@make -C $(MLX_PATH)

$(NAME): $(LIBFT) $(MLX) $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBFT) $(MLX) $(MLXFLAGS)

$(OBJ_DIR)/%.o: %.c $(HEADER_FILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

bonus: $(OBJ_DIR_BONUS) $(NAME_BONUS)

$(OBJ_DIR_BONUS):
	@mkdir -p $(OBJ_DIR_BONUS)

$(NAME_BONUS): $(LIBFT) $(MLX) $(OBJ_FILES_BONUS)
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_FILES_BONUS) $(LIBFT) $(MLX) $(MLXFLAGS)

$(OBJ_DIR_BONUS)/%.o: %.c $(HEADER_FILES_BONUS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@$(RM) $(OBJ_FILES)
	@$(RM) $(OBJ_FILES_BONUS)

fclean: clean
	@make fclean -C $(LIBFT_PATH) --no-print-directory
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM_DIR) $(OBJ_DIR)
	@$(RM_DIR) $(OBJ_DIR_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
