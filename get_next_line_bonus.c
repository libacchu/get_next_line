/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/03/10 23:20:17 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	char	*final;

	final = (char *)s;
	while (*final)
	{
		if (*final == c)
			return (final);
		final++;
	}
	return (NULL);
}

char	*ft_other_str(char *stat)
{
	char	*line;
	size_t	len;
	size_t	start;

	if (ft_strchr(stat, '\n'))
	{
		start = (ft_strlen(stat) - ft_strlen(ft_strchr(stat, '\n'))) + 1;
		len = ft_strlen(ft_strchr(stat, '\n')) - 1;
	}
	else
	{
		free(stat);
		return (NULL);
	}
	line = ft_substr(stat, start, len);
	free(stat);
	return (line);
}

char	*ft_get_line(char *stat)
{
	size_t	len;

	if (!stat[0])
		return (NULL);
	if (ft_strchr(stat, '\n'))
		len = ft_strlen(stat) - ft_strlen(ft_strchr(stat, '\n')) + 1;
	else
		len = ft_strlen(stat);
	return (ft_substr(stat, 0, len));
}

char	*ft_read(int fd, char *stat)
{
	char	*buff;
	int		read_size;

	if (stat == NULL)
		stat = ft_calloc(1, 1);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_size] = '\0';
		stat = ft_strjoin(stat, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (stat);
}

char	*get_next_line(int fd)
{
	static char		*stat[10496];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > 10496)
		return (NULL);
	stat[fd] = ft_read(fd, stat[fd]);
	if (!stat[fd])
		return (NULL);
	line = ft_get_line(stat[fd]);
	stat[fd] = ft_other_str(stat[fd]);
	return (line);
}
