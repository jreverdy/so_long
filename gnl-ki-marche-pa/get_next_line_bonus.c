/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:22:32 by jereverd          #+#    #+#             */
/*   Updated: 2021/12/14 15:22:33 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_rest(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	i += 1;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}

int	security_ret(int ret, char *line)
{
	if (ret == -1)
	{
		free(line);
		return (-1);
	}
	return (0);
}

int	security_line(char *line)
{
	if (line == NULL || line[0] == 0)
	{
		free(line);
		return (-1);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1] = {{0}};
	int			read_ret;

	line = NULL;
	read_ret = 1;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	while (read_ret > 0)
	{
		line = ft_strjoin(line, buffer[fd], -1, 0);
		if (check_buffer(buffer[fd]) == 1)
		{
			ft_save_rest(buffer[fd]);
			return (line);
		}
		read_ret = read(fd, buffer[fd], BUFFER_SIZE);
		if (security_ret(read_ret, line) == -1)
			return (NULL);
		buffer[fd][read_ret] = '\0';
	}
	if (security_line(line) == -1)
		return (NULL);
	return (line);
}
