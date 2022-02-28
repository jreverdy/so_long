/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:25:55 by jereverd          #+#    #+#             */
/*   Updated: 2022/01/04 13:25:58 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	ft_invalid_arg(int ac, char *str)
{
	int	i;

	i = 0;
	if (ac != 2)
		return (0);
	while (str[i])
		i++;
	i -= 1;
	if (str[i - 4] && str[i - 3] == '.' && str[i - 2] == 'b' \
		&& str[i - 1] == 'e' && str[i] == 'r')
		return (1);
	else
		return (0);
}

void	ft_print_error_msg(t_map *map_info, int i)
{
	if (i == 0)
	{
		ft_printf("Invalid arguments\n");
		exit(0);
	}
	else if (i == 2)
	{
		ft_printf("The map is not rectangular\n");
		exit(0);
	}
	else if (i == 3)
	{
		ft_printf("Wrong char in map\n");
		exit(0);
	}
	else if (check_map_char_number(map_info) == 0)
	{
		ft_printf("There is not at least 1 collectible, 1 player or 1 exit\n");
		exit(0);
	}
	else if (i == 4)
	{
		ft_printf("The init of map has failed\n");
		exit(0);
	}
}
