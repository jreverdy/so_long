/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:44:05 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/17 16:44:06 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_destroy(t_all *a)
{
	mlx_destroy_image(a->g->mlx, a->img->grass);
	mlx_destroy_image(a->g->mlx, a->img->hgrass);
	mlx_destroy_image(a->g->mlx, a->img->pfront);
	mlx_destroy_image(a->g->mlx, a->img->pokeball);
	mlx_destroy_image(a->g->mlx, a->img->wall);
	mlx_destroy_image(a->g->mlx, a->img->exit);
	mlx_destroy_window(a->g->mlx, a->g->win);
	ft_free(a->m);
	printf("Thanks for playing, Have a nice day :)\n");
	exit(0);
}
