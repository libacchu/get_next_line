/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/03/04 19:09:46 by libacchu         ###   ########.fr       */
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
	{	
		return (NULL);
	}
	if (ft_strchr(stat, '\n'))
		len = ft_strlen(stat) - ft_strlen(ft_strchr(stat, '\n')) + 1;
	else
		len = ft_strlen(stat) + 1;
	line = ft_substr(stat, 0, len);
	return (line);
}

char	*ft_read(int fd, char *stat)
{
	char	*buff;
	int		read_size;
	// char	*free_me;
	
	// char	*holder;

	if (stat == NULL)
		stat = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buff[BUFFER_SIZE] = '\0';
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		stat = ft_strjoin(stat, buff);
		if (ft_strchr(stat, '\n'))
			break ;
	}
	// holder = stat;
	// printf("stat = *%s*\n", stat);
	// if (!read_size || !stat)
	// free_me = stat;
	// printf("free_me = *%s*\n", free_me);
	free(buff);
	// free(stat);
	// free(stat);
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
	// printf("stat = *%s*\n", stat);
	if (!stat[0])
	{
		free(stat);
		return (NULL);
	}	
	// str = stat;
	// free(stat);
	line = ft_get_line(stat);
	stat = ft_other_str(stat);
	// printf("\nstat = *%s*\n", stat);
	return (line);
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
// 	int		i;
// 	int		lines;

// 	fd = open("./test.txt", O_RDONLY);
// 	lines = 0;
// 	printf("Enter number of lines: ");
// 	scanf("%d", &lines);
// 	i = 1;
// 	while (i <= lines)
// 	{
// 		printf("\nget next line %d = *%s*\n", i, get_next_line(fd));
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
