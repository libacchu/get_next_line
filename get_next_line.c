/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/02/24 12:00:41 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*ptr;
	char			buff[BUFFER_SIZE];
	size_t			read_size;

	read_size = read(fd, buff, BUFFER_SIZE);
	ptr = ft_calloc(BUFFER_SIZE, sizeof(char));
	ptr = ft_strdup(buff);
	while (read_size <= BUFFER_SIZE && read_size > 0)
	{
		printf("ptr = *%s*\n", ptr);
		if (ft_strchr(ptr, '\n'))
			break;
		printf("----HERE----\n");
		read_size = read(fd, buff, BUFFER_SIZE);
		ptr = ft_strjoin(ptr, buff);
	}
	return (ptr);
}

int	main(void)
{
	int		fd;

	fd = open("./test.txt", O_RDONLY);
	printf("get next line = %s\n\n\n", get_next_line(fd));
	// printf("get next line = %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
