/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:24:00 by jereverd          #+#    #+#             */
/*   Updated: 2021/12/17 14:24:01 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <limits.h>
#define BUFFER_SIZE 1

typedef struct s_map
{
	char	**map;
	int		x;
	int 	y;
	int 	collect;
	int 	player;
	int 	exit;
}				t_map;

char	*get_next_line(int fd);

#endif //SO_LONG_H
