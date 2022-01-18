/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:24:00 by jereverd          #+#    #+#             */
/*   Updated: 2021/12/17 14:24:01 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../incs/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <limits.h>

//KEYCODE = W = 13
//KEYCODE = A = 0
//KEYCODE = S = 1
//KEYCODE = D = 2
//KEYCODE = ESC = 53

typedef struct s_pos
{
	int x;
	int y;
}t_pos;

typedef struct s_val
{
	int		save;
	int		fd;
	char	*str;
}t_val;

typedef struct s_map
{
	char	**map;
	int		x;
	int 	y;
	int 	collectnb;
	int 	playernb;
	int 	exit;
	t_pos	player;
	int		step;
}t_map;

typedef struct s_game
{
	void	*mlx;
	void 	*win;
}t_game;

typedef struct s_image
{
	int		img_width;
	int		img_height;
	void 	*grass;
	void 	*hgrass;
	void	*pfront;
	void 	*pokeball;
	void 	*wall;
	void 	*exit;
	int		x[1];
	int		y[1];
}t_image;

typedef struct s_all
{
	t_map	*m;
	t_game	*g;
	t_image	*img;
}t_all;

int		ft_parsing(char *ber, t_map *map_info);
int		check_map_char_number(t_map *map_info);
int 	check_string(char *str, int side, t_map *map_info);

int 	ft_print(t_map *map_info,t_image *img, t_game *g);
void 	print_w(t_image *img, t_game *g, int x, int y);
void 	print_g(t_image *img, t_game *g, int x, int y);
void 	print_e(t_image *img, t_game *g, int x, int y);
void 	print_p(t_image *img, t_game *g, int x, int y);
void 	print_c(t_image *img, t_game *g, int x, int y);
void	print_ep(t_all *a);


int		ft_check_args(char *str);
void	ft_print_error_msg(t_map *map_info, int i);
int		ft_invalid_arg(int ac, char *str);

int		ft_collectible(int k, t_all *a);
void	ft_exit(int k, t_all *a);
void	ft_free(t_map *map_info);
int		ft_destroy(t_all *a);
int 	ft_check_exit(int k, t_all *a);

int		ft_key_hook(int keycode, t_all *a);
int		ft_move_up (t_all *a);
int		ft_move_left(t_all *a);
int		ft_move_back(t_all *a);
int		ft_move_right(t_all *a);

#endif //SO_LONG_H
