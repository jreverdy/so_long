NAME		=	so_long

INCS		=	./incs/so_long.h 		\
				./incs/get_next_line.h	\

OBJS_PATH	= .obj

SRCS		=	./srcs/so_long.c 				\
				./srcs/ft_parsing.c				\
				./srcs/ft_print.c				\
				./srcs/ft_print_texture.c		\
				./srcs/get_next_line.c			\
				./srcs/get_next_line_utils.c	\
				./srcs/ft_check_args.c			\
				./srcs/ft_movement.c			\
				./srcs/ft_collectible.c			\
				./srcs/ft_exit.c				\
				./srcs/ft_free.c				\
				./srcs/ft_destroy.c				\
				./srcs/ft_checker.c				\

LIBFT_AR	=	./libft/libft.a

PRINTF_AR	=	./ft_printf/libftprintf.a

OBJS		=	$(addprefix $(OBJS_PATH)/, ${SRCS:.c=.o})

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -I mlx

RM			=	rm -rf

all : ft_printf libft mlx $(NAME)

libft:
	@make -C ./libft

ft_printf:
	@make -C ./ft_printf

mlx:
	@make -C ./mlx

$(OBJS_PATH)/%.o: %.c $(INCS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_AR) $(PRINTF_AR)
	$(CC) $(OBJS) $(LIBFT_AR) $(PRINTF_AR) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C ./libft
	make clean -C ./mlx
	make clean -C ./ft_printf

fclean: clean
	$(RM) $(LIBFT_AR)
	$(RM) $(PRINTF_AR)
	$(RM) ./mlx/libmlx.a
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft ft_printf mlx clean fclean re