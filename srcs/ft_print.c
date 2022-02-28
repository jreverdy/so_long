/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:58:01 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/04 14:58:02 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_print(t_map *map_info, t_image *img, t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] == '1')
				print_w(img, g, x, y);
			else if (map_info->map[y][x] == '0')
				print_g(img, g, x, y);
			else if (map_info->map[y][x] == 'P')
				print_g(img, g, x, y);
			else if (map_info->map[y][x] == 'E')
				print_e(img, g, x, y);
			else if (map_info->map[y][x] == 'C')
				print_c(img, g, x, y);
			print_p(img, g, map_info->player.x, map_info->player.y);
			x++;
		}
		y++;
	}
	return (0);
}
