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

int 	init_map(char *ber, t_map *map_info)
{
	int		fd;
	char	*str;
	int 	i;

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
		(*map_info)->player++;
	if (c == 'E')
		(*map_info)->exit++;
	if (c == 'C')
		(*map_info)->collect++;
}

int check_string(char *str, int side, t_map *map_info)
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
		else if (str[i] != '1' && str[i] != '0' && str[i] != 'P' && str[i] != 'E' && str[i] != 'C' )
			return (0);
		count_params(str[i], &map_info);
		i++;
	}
	return (1);
}

int	check_map_errors(t_map *map_info)
{
	if (map_info->collect < 1)
		return (0);
	if (map_info->player != 1)
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
	if (!check_map_errors(map_info))
		return (0);
	close(fd);
	return (1);
}

int get_map_values(char *ber, t_map *map_info)
{
	int		fd;
	char	*str;
	int		save;

	fd = open(ber, O_RDONLY);
	if (fd == -1)
		return (0);
	save = -1;
	str = get_next_line(fd);
	while (str)
	{
		if (save == -1)
			save = ft_strlen(str);
		map_info->x = ft_strlen(str);
		if (map_info->x != save)
		{
			free(str);
			return (0);
		}
		map_info->y++;
		free(str);
		str = get_next_line(fd);
		if (!str)
			break ;
	}
	close(fd);
	return (1);
}

void 	init_struct(t_map *map_info)
{
	map_info->x = 0;
	map_info->y = 0;
	map_info->player = 0;
	map_info->collect = 0;
	map_info->exit = 0;
	map_info->map = NULL;
}

int	ft_parsing(char *ber, t_map *map_info)
{
	if (!get_map_values(ber, map_info))
	{
		printf("map_error in values\n");
		return (0);
	}
	if (!check_map_char(ber, map_info))
	{
		printf("map_error in char\n");
		return (0);
	}
	if (!init_map(ber, map_info))
	{
		printf("map_error in init\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_map map_info;

	init_struct(&map_info);
	if (!ft_parsing(av[1], &map_info))
		return (1);
	printf("Player=%d, Exit=%d Collect=%d\n", map_info.player, map_info.exit, map_info.collect);
	int i = 0;
	if (map_info.map)
	{
		while (map_info.map[i])
		{
			printf("%s\n", map_info.map[i]);
			i++;
		}
	}
}

//void 	delete_newline(char *ber, int fd)
//{
//	char	*str;
//	char 	*new_str;
//	int		i;
//
//	i = 0;
//	str = get_next_line(fd);
//	while(str[i] != '\n')
//	{
//		new_str[i] = str[i];
//		i++;
//	}
//	str[i] = '\0';
//}