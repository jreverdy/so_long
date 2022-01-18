/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:26:49 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/06 10:26:50 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"


int	ft_move_up(t_all *a)
{
	printf("The player move up\n");
	if (a->m->map[a->m->player.y - 1][a->m->player.x] != '1')
	{
		a->m->player.y--;
		if (a->m->map[a->m->player.y][a->m->player.x] == 'C')
			a->m->map[a->m->player.y][a->m->player.x] = '0';
	}
	return (0);
}

int	ft_move_left(t_all *a)
{
	printf("The player move left\n");
	if (a->m->map[a->m->player.y][a->m->player.x - 1] != '1')
	{
		a->m->player.x--;
		if (a->m->map[a->m->player.y][a->m->player.x] == 'C')
			a->m->map[a->m->player.y][a->m->player.x] = '0';
	}
	a->m->step++;
	return (0);
}

int	ft_move_back(t_all *a)
{
	printf("The player move down\n");
	if (a->m->map[a->m->player.y + 1][a->m->player.x] != '1')
	{
		a->m->player.y++;
		if (a->m->map[a->m->player.y][a->m->player.x] == 'C')
			a->m->map[a->m->player.y][a->m->player.x] = '0';
	}
	a->m->step++;
	return (0);
}

int	ft_move_right(t_all *a)
{
	printf("The player move right\n");
	if (a->m->map[a->m->player.y][a->m->player.x + 1] != '1')
	{
		a->m->player.x++;
		if (a->m->map[a->m->player.y][a->m->player.x] == 'C')
			a->m->map[a->m->player.y][a->m->player.x] = '0';
	}
	a->m->step++;
	return (0);
}