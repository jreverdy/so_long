/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:36:54 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/13 17:36:55 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_collectible(int k, t_all *a)
{
	if (k == 13 && a->m->map[a->m->player.y - 1][a->m->player.x] == 'C')
		a->m->collectnb--;
	else if (k == 0 && a->m->map[a->m->player.y][a->m->player.x - 1] == 'C')
		a->m->collectnb--;
	else if (k == 1 && a->m->map[a->m->player.y + 1][a->m->player.x] == 'C')
		a->m->collectnb--;
	else if (k == 2 && a->m->map[a->m->player.y][a->m->player.x + 1] == 'C')
		a->m->collectnb--;
	if (a->m->collectnb == 0)
		return (1);
	else
		return (0);
}
