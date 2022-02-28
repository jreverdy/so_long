/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:02:33 by jereverd          #+#    #+#             */
/*   Updated: 2021/12/29 15:02:36 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../incs/so_long.h"

void	init_image(t_game *g, t_image *i)
{
	i->grass = mlx_xpm_file_to_image(g->mlx, "img/grass.xpm", \
	i->x, i->y);
	i->hgrass = mlx_xpm_file_to_image(g->mlx, "img/hgrass.xpm", \
	i->x, i->y);
	i->pfront = mlx_xpm_file_to_image(g->mlx, "img/pfront.xpm", \
	i->x, i->y);
	i->pokeball = mlx_xpm_file_to_image(g->mlx, "img/pokeball.xpm", \
	i->x, i->y);
	i->wall = mlx_xpm_file_to_image(g->mlx, "img/wall.xpm", \
	i->x, i->y);
	i->exit = mlx_xpm_file_to_image(g->mlx, "img/exit.xpm", \
	i->x, i->y);
}

int	ft_key_hook(int keycode, t_all *a)
{
	char	*step;

	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		if (ft_collectible(keycode, a) == 1)
			ft_exit(keycode, a);
	}
	if (keycode == 13)
		ft_move_up(a);
	else if (keycode == 0)
		ft_move_left(a);
	else if (keycode == 1)
		ft_move_back(a);
	else if (keycode == 2)
		ft_move_right(a);
	else if (keycode == 17 || keycode == 53)
		ft_destroy(a);
	ft_print(a->m, a->img, a->g);
	step = ft_itoa(a->m->step);
	mlx_string_put(a->g->mlx, a->g->win, 10, 15, 0xff0000, step);
	if (step)
		free(step);
	return (0);
}

int	main(int ac, char **av)
{
	t_val	v;
	t_map	map_info;
	t_game	g;
	t_image	img;
	t_all	a;

	a.v = &v;
	a.m = &map_info;
	a.img = &img;
	a.g = &g;
	if (ft_invalid_arg(ac, av[1]) == 0)
	{
		ft_print_error_msg(&map_info, 0);
		return (0);
	}
	ft_parsing(av[1], &a);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, a.m->x * 32, a.m->y * 32, "so_long");
	init_image(&g, a.img);
	ft_print(a.m, a.img, a.g);
	mlx_hook(g.win, 2, 0, ft_key_hook, &a);
	mlx_hook(g.win, 17, 0, ft_destroy, &a);
	mlx_loop(g.mlx);
	return (0);
}
