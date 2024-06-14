NAME		=	so_long

SRC			=	$(addprefix src/, main.c check_map.c get_images.c)

OBJ			= $(SRC:.c=.o)

LIBFT_PATH	= libft/

LIBFT_NAME	= libft.a

LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

CC			=	cc

RM 			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

MLX_FLAGS	=	-Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME) $(LIBFT)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind -s --leak-check=full --track-origins=yes ./$(NAME) map.ber

.PHONY: all clean fclean re valgrind
