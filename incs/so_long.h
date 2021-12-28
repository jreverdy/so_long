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

typedef struct s_map
{
	char	**map;
	int 	y;
}				t_map;

size_t	ft_strlen(char *str);

#endif //SO_LONG_H
