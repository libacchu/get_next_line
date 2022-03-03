/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/03/03 11:06:22 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_other_str(char *stat)
{
	char	*line;
	size_t	x;
	size_t	y;

	x = ft_strlen(stat);
	y = ft_strlen(ft_strchr(stat, '\n'));
	line = ft_substr(stat, (x - y) + 1, (y - 1));
	// printf("line = *%s*", line);
	return (line);
}

char	*ft_get_line(char *stat)
{
	char	*line;
	int		x;
	int		y;

	x = ft_strlen(stat);
	y = ft_strlen(ft_strchr(stat, '\n'));
	line = ft_substr(stat, 0, (x - y));
	return (line);
}

char	*ft_read(int fd, char *stat)
{
	char	*buff;
	int		read_size;

	if (stat == NULL)
		stat = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		stat = ft_strjoin(stat, buff);
		if (ft_strchr(stat, '\n'))
			break ;
	}
	free(buff);
	return (stat);
}

char	*get_next_line(int fd)
{
	static char		*stat;
	char			*line;
	char			*str;

	// printf("stat = *%s*\n", stat);
	stat = ft_read(fd, stat);
	line = ft_calloc(1, 1);
	line = ft_get_line(stat);
	// free(stat);
	stat = ft_other_str(stat);
	str = line;
	// free(line);
	// printf("line = *%s*\n", line);
	return (str);
}

// char	*get_next_line(int fd)
// {
// 	static char		*ptr;
// 	char			buff[BUFFER_SIZE];
// 	char			*final;
// 	size_t			read_size;
// 	size_t			x;
// 	size_t			y;

// 	read_size = read(fd, buff, 1);
// 	ptr = ft_calloc(1, sizeof(char));
// 	ptr = ft_strdup(buff);
// 	while (read_size > 0)
// 	{
// 		if (ft_strchr(ptr, '\n'))
// 			break;
// 		read_size = read(fd, buff, 1);
// 		ptr = ft_strjoin(ptr, buff);
// 	}
// 	x = ft_strlen(ptr);
// 	y = ft_strlen(ft_strchr(ptr, '\n'));
// 	final = ft_substr(ptr, 0, (x - y));
// 	ptr = ft_strchr(ptr, '\n');
// 	return (final);
// }

// char	*get_next_line(int fd)
// {
// 	char			*ptr;
// 	static char		buff;
// 	int				amtread;
// 	char			*join;

// 	ptr = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	amtread = 1;
// 	while (amtread > 0)
// 	{
// 		amtread = read(fd, ptr, BUFFER_SIZE);
// 		ptr[amtread] = '\0';
// 		join = ft_strjoin(&buff, ptr);
// 		if (ft_strchr(join, '\n'))
// 			break;
// 	}
// 	free(ptr);
// 	return (join);
// }

// int	main(void)
// {
// 	int		fd;
// 	// char	*s1 = "This is a string";
// 	// char	*s2;
// 	// s2 = ft_substr(s1, 1, 4);
// 	// printf("s2 = *%s*\n", s2);
// 	fd = open("./test.txt", O_RDONLY);
// 	// while (get_next_line(fd))
// 	// 	printf("get next line = *%s*\n\n", get_next_line(fd));
// 	printf("get next line = *%s*\n", get_next_line(fd));
// 	printf("get next line = *%s*\n\n", get_next_line(fd));
// 	printf("get next line = *%s*\n\n", get_next_line(fd));
// 	printf("get next line = *%s*\n\n", get_next_line(fd));
// 	printf("get next line = *%s*\n\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
