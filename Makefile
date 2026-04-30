# ============================================================================
# CUB3D MAKEFILE
# ============================================================================

NAME			= cub3D
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -std=gnu89 -g
INCLUDES		= -I./includes -I./libft -I./gnl -I./minilibx-linux-master
RM				= rm -f

# ============================================================================
# DIRECTORIES
# ============================================================================

SOURCES_DIR		= sources
#Parsing
PARSING_DIR		= $(SOURCES_DIR)/parsing
INFO_DIR		= $(PARSING_DIR)/info
MAP_DIR			= $(PARSING_DIR)/map
#Rendering
RENDERING_DIR	= $(SOURCES_DIR)/rendering

BUILD_DIR		= build
LIBFT_DIR		= libft
MLX_DIR			= minilibx-linux-master
GNL_DIR			= gnl

# ============================================================================
# SOURCE FILES
# ============================================================================

INFO			= $(INFO_DIR)/info.c \
				  $(INFO_DIR)/colors.c \
				  $(INFO_DIR)/utils.c

MAP				= $(MAP_DIR)/maps.c \
				  $(MAP_DIR)/floodfill.c \
				  $(MAP_DIR)/linked_list.c \
				  $(MAP_DIR)/utils.c

PARSING			= $(PARSING_DIR)/parsing.c \
				  $(PARSING_DIR)/utils.c \
				  $(INFO) $(MAP)

RENDERING		= $(RENDERING_DIR)/rendering.c \
				  $(RENDERING_DIR)/draw.c \
				  $(RENDERING_DIR)/textures.c \
				  $(RENDERING_DIR)/hooks.c \
				  $(RENDERING_DIR)/raycasting.c \
				  $(RENDERING_DIR)/render3d.c \
				  $(RENDERING_DIR)/movement.c \
				  $(RENDERING_DIR)/movement_utils.c

SOURCES			= $(SOURCES_DIR)/main.c \
				  $(SOURCES_DIR)/utils.c \
				  $(SOURCES_DIR)/ft_math.c \
				  $(PARSING) $(RENDERING)

OBJECTS			= $(SOURCES:%.c=$(BUILD_DIR)/%.o)

# LIBFT
LIBFT_NAME		= $(LIBFT_DIR)/libft.a

# MLX
MLX_NAME		= $(MLX_DIR)/libmlx.a
MLX_FLAGS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# GET_NEXT_LINE
GNL_FILES		= get_next_line.c get_next_line_utils.c
GNL_OBJECTS		= $(GNL_FILES:%.c=$(BUILD_DIR)/gnl/%.o)

# ============================================================================
# RULES
# ============================================================================

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(MLX_NAME) $(OBJECTS) $(GNL_OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(GNL_OBJECTS) -L$(LIBFT_DIR) -lft $(MLX_FLAGS) $(INCLUDES) -o $(NAME)
	@echo "✓ $(NAME) built successfully!"

# LIBFT Rules (uses libft's own makefile)
$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)
	@echo "✓ libft compiled!"

# MLX Rules
$(MLX_NAME):
	@make -C $(MLX_DIR)
	@echo "✓ minilibx compiled!"

# GET_NEXT_LINE Rules
$(BUILD_DIR)/gnl/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(BUILD_DIR)/gnl
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# CUB3D Rules
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)/$(SOURCES_DIR)
	@mkdir -p $(BUILD_DIR)/$(PARSING_DIR)
	@mkdir -p $(BUILD_DIR)/$(INFO_DIR)
	@mkdir -p $(BUILD_DIR)/$(MAP_DIR)
	@mkdir -p $(BUILD_DIR)/$(RENDERING_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)
	@make -C $(LIBFT_DIR) clean
	-@make -C $(MLX_DIR) clean
	@echo "✓ Build files cleaned!"

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "✓ Everything cleaned!"

re: fclean all

.PHONY: all clean fclean re
