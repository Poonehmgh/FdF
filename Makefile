NAME = fdf

SRC_DIR = Source

SRCS =  $(SRC_DIR)/fdf.c $(SRC_DIR)/color.c $(SRC_DIR)/line.c $(SRC_DIR)/reading_map.c \
		$(SRC_DIR)/draw.c $(SRC_DIR)/errors.c $(SRC_DIR)/events.c $(SRC_DIR)/events2.c \
		$(SRC_DIR)/map_check.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MINILIBX_MAC = minilibx_macos/libmlx.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@$(MAKE) -C minilibx_macos
	@$(CC) $(OBJS) $(LIBFT) $(MINILIBX_MAC) -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re
