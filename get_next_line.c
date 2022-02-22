/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 10:33:05 by libacchu          #+#    #+#             */
/*   Updated: 2022/02/22 10:47:51 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void	*buff;
	// int		i;
	
	buff = malloc(BUFFER_SIZE);
	read(fd, buff, BUFFER_SIZE);
	// i = 0;
	// while (buff != '\n')
	// 	i++;
	return ((char *)buff);
}

int	main(void)
{
	int		fd;

	fd = open("./test.txt", O_RDONLY);
	printf("get next line = %s\n", get_next_line(fd));
	close(fd);
	return (0);
}
