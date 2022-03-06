/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/03/05 16:09:42 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_other_str(char *stat)
{
	char	*line;
	size_t	len;
	size_t	start;
	// printf("\n----------PASSED-----------\n");

	if (ft_strchr(stat, '\n'))
	{
		start = (ft_strlen(stat) - ft_strlen(ft_strchr(stat, '\n'))) + 1;
		// printf("*%zu* ---- *%zu*\n", ft_strlen(stat), ft_strlen(ft_strchr(stat, '\n')));
		len = ft_strlen(ft_strchr(stat, '\n')) - 1;
	}
	else
		return (NULL);
	// line = ft_substr(stat, (x - y) + 1, (y - 1));
	line = ft_substr(stat, start, len);
	// printf("line = *%s*", line);
	return (line);
}

char	*ft_get_line(char *stat)
{
	char	*line;
	size_t	len;

	// printf("stat = *%s*\n", stat);
	if (stat == 0)
		return (NULL);
	if (ft_strchr(stat, '\n'))
		len = ft_strlen(stat) - ft_strlen(ft_strchr(stat, '\n')) + 1;
	else
		len = ft_strlen(stat);
	line = ft_substr(stat, 0, len);
	return (line);
}

char	*ft_read(int fd, char *stat)
{
	char	*buff;
	int		read_size;
	char	*temp;

	if (stat == NULL)
		stat = ft_calloc(1, 1);
	read_size = 1;
	while (read_size > 0)
	{
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		buff[BUFFER_SIZE] = '\0';
		read_size = read(fd, buff, BUFFER_SIZE);
		temp = ft_strjoin(stat, buff);
		if (ft_strchr(stat, '\n'))
			break ;
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
	// char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stat = ft_read(fd, stat);
	// printf("stat 			= *%s*\n", stat);
	if (!stat[0])
	{
		free(stat);
		return (NULL);
	}	
	// str = stat;
	// free(stat);
	line = ft_get_line(stat);
	// printf("line 			= *%s*\n", line);
	if (ft_strchr(stat, '\0'))
	{
		free(stat);
		// printf("-----HERE-----\n");
	}
	else
		stat = ft_other_str(stat);
	// printf("\nstat = *%s*\n", stat);
	return (line);
}
