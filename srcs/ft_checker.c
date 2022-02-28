/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:49:20 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/18 17:49:21 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	check_map_char_number(t_map *map_info)
{
	if (map_info->collectnb < 1)
		return (0);
	if (map_info->playernb != 1)
		return (0);
	if (map_info->exit < 1)
		return (0);
	return (1);
}

int	check_map_char(char *ber, t_map *map_info)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(ber, O_RDONLY);
	if (fd == -1)
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		if (check_string(str, i, map_info) == 0)
		{
			free(str);
			close (fd);
			return (0);
		}
		i++;
		free(str);
		str = get_next_line(fd);
	}
	if (!check_map_char_number(map_info))
		return (0);
	close(fd);
	return (1);
}

int	check_string(char *str, int side, t_map *map_info)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0] != '1' || str[map_info->x - 1] != '1')
			return (0);
		if (side == 0 || side == map_info->y)
		{
			if (str[i] != '1')
				return (0);
		}
		else if (str[i] != '1' && str[i] != '0' && str[i] != 'P' \
			&& str[i] != 'E' && str[i] != 'C' )
			return (0);
		if (str[i] == 'P')
		{
			map_info->player.x = i;
			map_info->player.y = side;
		}
		count_params(str[i], &map_info);
		i++;
	}
	return (1);
}
