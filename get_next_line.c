/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/03/07 11:32:52 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	size_t	len;
	size_t	start;

	if (ft_strchr(stat, '\n'))
	{
		start = (ft_strlen(stat) - ft_strlen(ft_strchr(stat, '\n'))) + 1;
		len = ft_strlen(ft_strchr(stat, '\n')) - 1;
	}
	else
		return (NULL);
	return (ft_substr(stat, start, len));
}

char	*ft_get_line(char *stat)
{
	size_t	len;

	if (stat == 0)
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
	char	*temp;

	read_size = 1;
	while (read_size > 0)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		read_size = read(fd, buff, BUFFER_SIZE);
		buff[read_size] = '\0';
		temp = ft_strjoin(stat, buff);
		if (ft_strchr(buff, '\n'))
		{
			free(buff);
			free(stat);
			stat = ft_strdup(temp);
			free(temp);
			break ;
		}
		free(buff);
		free(stat);
		stat = ft_strdup(temp);
		free(temp);
	}
	return (stat);
}

char	*get_next_line(int fd)
{
	static char		*stat;
	char			*line;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (stat == NULL)
		stat = ft_calloc(1, 1);
	stat = ft_read(fd, stat);
	if (!stat[0])
	{
		free(stat);
		return (NULL);
	}	
	temp = ft_strdup(stat);
	free(stat);
	stat = ft_other_str(temp);
	line = ft_get_line(temp);
	free(temp);
	return (line);
}
