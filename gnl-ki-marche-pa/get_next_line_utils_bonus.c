/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereverd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:22:38 by jereverd          #+#    #+#             */
/*   Updated: 2021/12/14 15:22:39 by jereverd         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	check_buffer(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, size_t i, size_t j)
{
	char		*str;
	size_t		len_s1;
	size_t		len_s2;

	if (s1 == NULL && !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (++i < len_s1)
		str[i] = s1[i];
	while ((s2[j] != '\n') && (j < len_s2))
		str[i++] = s2[j++];
	if (s2 && s2[j] == '\n')
		str[i++] = s2[j];
	str[i] = '\0';
	free(s1);
	return (str);
}
