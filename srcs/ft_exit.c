/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:43 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/13 17:36:44 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	ft_exit(int k, t_all *a)
{
	if (k == 13 && a->m->map[a->m->player.y - 1][a->m->player.x] == 'E')
	{
		ft_printf("YOU WIN !!!\n");
		exit(0);
	}
	else if (k == 0 && a->m->map[a->m->player.y][a->m->player.x - 1] == 'E')
	{
		ft_printf("YOU WIN !!!\n");
		exit(0);
	}
	else if (k == 1 && a->m->map[a->m->player.y + 1][a->m->player.x] == 'E')
	{
		ft_printf("YOU WIN !!!\n");
		exit(0);
	}
	else if (k == 2 && a->m->map[a->m->player.y][a->m->player.x + 1] == 'E')
	{
		ft_printf("YOU WIN !!!\n");
		exit(0);
	}
	else if (k == 53)
		exit(0);
}
