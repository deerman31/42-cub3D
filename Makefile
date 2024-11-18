NAME			:= cub3D
OBJ_DIR			:= obj
SRC_DIR			:= src
INCLUDE			:= include
MLX_DIR			:= minilibx
MLX				:= mlx
X11				:= //usr/X11/include/../lib

CC				:= cc
FLAGS			:= -Wall -Wextra -Werror
#FLAGS			+= -g -fsanitize=address
LINKS			:= -L $(MLX_DIR) -l $(MLX) -L $(X11) -lXext -lX11 -lm
SRCS_NAME		:=	main.c \
				./draw/buf_set.c ./draw/calculation.c ./draw/cross_dis.c ./draw/cross_dis_utils.c ./draw/dir_dis.c ./draw/dis_check.c ./draw/draw.c ./draw/first_cross.c ./draw/offset.c \
				./game/game_close.c ./game/game_play.c ./game/key_op.c \
				./init/init.c ./init/set_ray.c ./init/texture_set.c \
				./parse/parse.c ./parse/arg_check.c ./parse/element_num_check.c ./parse/element_set.c ./parse/element_value_check.c ./parse/get_map.c ./parse/get_text.c ./parse/map_mark_check.c ./parse/re_map.c ./parse/set_map.c ./parse/set_player.c \
				./utils/free.c ./utils/utils1.c ./utils/utils2.c ./utils/utils3.c ./utils/utils4.c ./utils/utils5.c

SRCS			:= $(addprefix $(SRC_DIR)/, $(SRCS_NAME))
OBJECTS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME):	$(OBJECTS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(FLAGS) $(LINKS) -I $(INCLUDE) -o $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C $(MLX_DIR)

re: fclean all

.PHONY: all fclean clean re
