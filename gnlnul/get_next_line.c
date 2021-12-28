/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:16:24 by mapontil          #+#    #+#             */
/*   Updated: 2021/11/15 11:53:51 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_checknl(char **str, char *afternl, char **buff)
{
	char	*buffnl;
	size_t	buffnl_len;

	buffnl = ft_strchr(*buff, '\n');
	buffnl_len = ft_strlen(buffnl);
	if (buffnl)
	{
		ft_strlcpy(afternl, buffnl + 1, buffnl_len - 1);
		*str = ft_strndup(NULL, *buff, ft_strlen(*buff) - buffnl_len + 1);
		return (*str);
	}
	return (NULL);
}

char	*ft_exit(char *str, char **temp)
{
	free(*temp);
	return (str);
}

int	ft_read(int fd, char *buff, int len)
{
	int	j;

	j = read(fd, buff, len);
	buff[j] = '\0';
	return (j);
}

char	*get_next_line(int fd)
{
	char		*temp;
	static char	afternl[BUFFER_SIZE + 1];
	char		buff[BUFFER_SIZE + 1];
	char		*str;
	int			j;

	str = NULL;
	temp = NULL;
	if (*afternl)
	{
		temp = ft_strjoin(temp, afternl);
		if (ft_checknl(&str, afternl, &temp))
			return (ft_exit(str, &temp));
		ft_strlcpy(afternl, "\0", 1);
	}
	j = BUFFER_SIZE;
	while (j > 0)
	{
		j = ft_read(fd, buff, BUFFER_SIZE);
		if (j > 0)
			temp = ft_strjoin(temp, buff);
		if (ft_checknl(&str, afternl, &temp))
			return (ft_exit(str, &temp));
	}
	return (temp);
}
