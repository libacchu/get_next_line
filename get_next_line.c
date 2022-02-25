/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/02/24 22:34:34 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*ptr;
	char			buff[BUFFER_SIZE];
	size_t			read_size;
	size_t			x;
	size_t			y;
	char			*final;

	read_size = read(fd, buff, BUFFER_SIZE);
	// ptr = ft_calloc(BUFFER_SIZE, sizeof(char));
	ptr = ft_strdup(buff);
	while (read_size <= BUFFER_SIZE && read_size > 0)
	{
		// printf("ptr = *%s*\n", ptr);
		if (ft_strchr(ptr, '\n'))
			break;
		read_size = read(fd, buff, BUFFER_SIZE);
		ptr = ft_strjoin(ptr, buff);
	}
	x = ft_strlen(ptr);
	y = ft_strlen(ft_strchr(ptr, '\n'));
	// printf("x = %zu | y = %zu\n", x, y);
	final = ft_substr(ptr, 0, (x - y));
	// printf("----HERE----\n");
	return (final);
}

// int	main(void)
// {
// 	int		fd;
// 	// char	*s1 = "This is a string";
// 	// char	*s2;
	
// 	// s2 = ft_substr(s1, 1, 4);
// 	// printf("s2 = *%s*\n", s2);
// 	fd = open("./test.txt", O_RDONLY);
// 	printf("get next line = *%s*\n\n\n", get_next_line(fd));
// 	printf("get next line = %s\n", get_next_line(fd));
// 	printf("get next line = %s\n", get_next_line(fd));
// 	printf("get next line = %s\n", get_next_line(fd));
// 	// close(fd);
// 	return (0);
// }
