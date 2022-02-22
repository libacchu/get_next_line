/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/02/22 12:18:27 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void			*buff;
	static int		j;
	size_t			i;
	char			*ptr;

	buff = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buff, BUFFER_SIZE);
	i = 0;
	j = 0;
	ptr = (char *)buff;
	while (ptr[i] != '\n')
	{
		i++;
	}
	ptr[i] = '\0';
	printf("%s\n", ptr);
	return (ptr);
}

int	main(void)
{
	int		fd;

	fd = open("./test.txt", O_RDONLY);
	printf("get next line = %s\n", get_next_line(fd));
	// printf("get next line = %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
