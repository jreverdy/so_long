/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:58:32 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/17 11:58:33 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	print_w(t_image *img, t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img->grass, x * 32, y * 32);
	mlx_put_image_to_window(g->mlx, g->win, img->wall, x * 32, y * 32);
}

void	print_g(t_image *img, t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img->grass, x * 32, y * 32);
}

void	print_e(t_image *img, t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img->grass, x * 32, y * 32);
	mlx_put_image_to_window(g->mlx, g->win, img->exit, x * 32, y * 32);
}

void	print_p(t_image *img, t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img->grass, x * 32, y * 32);
	mlx_put_image_to_window(g->mlx, g->win, img->pfront, x * 32, y * 32);
}

void	print_c(t_image *img, t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img->grass, x * 32, y * 32);
	mlx_put_image_to_window(g->mlx, g->win, img->pokeball, x * 32, y * 32);
}
