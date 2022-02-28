/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:21:33 by jereverd          #+#    #+#             */
/*   Updated: 2021/12/17 14:21:34 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	init_map(char *ber, t_map *map_info)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	map_info->map = ft_calloc(sizeof(char **), map_info->y + 1);
	if (!map_info->map)
		return (0);
	fd = open(ber, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		map_info->map[i] = str;
		i++;
		str = get_next_line(fd);
	}
	return (1);
}

void	count_params(char c, t_map **map_info)
{
	if (c == 'P')
		(*map_info)->playernb++;
	if (c == 'E')
		(*map_info)->exit++;
	if (c == 'C')
		(*map_info)->collectnb++;
}

int	get_map_values(char *ber, t_all *a)
{
	a->v->fd = open(ber, O_RDONLY);
	if (a->v->fd == -1)
		return (0);
	a->v->str = get_next_line(a->v->fd);
	while (a->v->str)
	{
		if (a->v->save == -1)
			a->v->save = ft_strlen(a->v->str);
		a->m->x = ft_strlen(a->v->str);
		if (a->m->x != a->v->save)
		{
			free(a->v->str);
			return (0);
		}
		a->m->y++;
		free(a->v->str);
		a->v->str = get_next_line(a->v->fd);
		if (!a->v->str)
			break ;
	}
	close(a->v->fd);
	return (1);
}

void	init_struct(t_all *a)
{
	a->v->save = -1;
	a->v->fd = 0;
	a->m->x = 0;
	a->m->y = 0;
	a->m->playernb = 0;
	a->m->collectnb = 0;
	a->m->exit = 0;
	a->m->map = NULL;
	a->g->mlx = NULL;
	a->g->win = NULL;
	a->m->step = 0;
}

int	ft_parsing(char *ber, t_all *a)
{
	int fd;

	fd = open(ber, O_RDWR);
	if (fd == -1)
	{
		ft_printf("Could not open file\n");
		exit (0);
	}
	close(fd);
	init_struct(a);
	if (!get_map_values(ber, a))
		ft_print_error_msg(a->m, 2);
	else if (!check_map_char(ber, a->m))
		ft_print_error_msg(a->m, 3);
	else if (!init_map(ber, a->m))
		ft_print_error_msg(a->m, 4);
	return (0);
}
