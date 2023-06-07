SRCS		= $(SRCS_DIR)/main.c \
				$(SRCS_DIR)/parse/file_handler.c \
				$(SRCS_DIR)/parse/check_args.c \
				$(SRCS_DIR)/parse/fill_args.c \
				$(SRCS_DIR)/parse/parse_main.c \
				$(SRCS_DIR)/parse/check_closed.c \
				$(SRCS_DIR)/parse/check_map.c \
				$(SRCS_DIR)/game/keys.c \
				$(SRCS_DIR)/game/render.c \
				$(SRCS_DIR)/init/init.c \
				$(SRCS_DIR)/utils/utils.c \
				$(SRCS_DIR)/utils/allocation.c \
				$(SRCS_DIR)/struct/struct.c \
				$(SRCS_DIR)/get_next_line/get_next_line.c \
				$(SRCS_DIR)/get_next_line/get_next_line_utils.c \

SRCS_DIR	= srcs

OBJS		= $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

OBJS_DIR	= objs

NAME		= cub3d

CC			= cc

MLX			= mlx_linux/libmlx_Linux.a

INC			= -I inc -I mlx_linux

CFLAGS 		= -Wall -Wextra -Werror $(INC) -g -fsanitize=address

RM 			= rm -rf
LIBS_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(MLX) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)

$(MLX):
	make -C mlx_linux

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c $< -o $@

test: re
	./cub3d teste.cub

clean:
	$(RM) $(OBJS_DIR) a.out
#	make clean -C mlx_linux
	
fclean: clean
	$(RM) $(NAME) $(OBJS)

re: fclean all
