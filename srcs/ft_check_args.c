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
		printf("Invalid arguments\n");
	else if (i == 2)
		printf("The map is not rectangular\n");
	else if (i == 3)
		printf("Wrong char in map\n");
	else if (check_map_char_number(map_info) == 0)
		printf("There is not at least 1 collectible, 1 player or 1 exit\n");
	else if (i == 4)
		printf("The init of map has failed\n");
}
