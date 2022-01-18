NAME		=	so_long

INCS		=	./incs/so_long.h 		\
				./incs/get_next_line.h	\

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

LIBFT_AR	=	./libft/libft.a

OBJS		=	${SRCS:.c=.o}

CC			=	clang

CFLAGS		=	-Wall -Wextra -Werror -I mlx

RM			=	rm -rf

all : libft mlx ${NAME}

libft:
	@make -C ./libft --no-print-directory

mlx:
	@make -C ./mlx --no-print-directory

%.o: %.c ${INCS}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT_AR}
	${CC} ${OBJS} ${LIBFT_AR} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	${RM} ${OBJS}
	make clean -C ./libft
	make clean -C ./mlx

fclean: clean
	${RM} ${LIBFT_AR}
	${RM} ./mlx/libmlx.a
	${RM} ${NAME}

re: fclean all

.PHONY: all libft mlx clean fclean re