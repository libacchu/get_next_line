/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:12:10 by libacchu          #+#    #+#             */
/*   Updated: 2022/03/05 16:17:56 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int	main(void)
{
	int	fd;
	int	i;
	int	lines;

	fd = open("./test.txt", O_RDONLY);
	lines = 0;
	printf("Enter number of lines: ");
	scanf("%d", &lines);
	i = 1;
	while (i <= lines)
	{
		printf("\nget next line %d 	= *%s*\n", i, get_next_line(fd));
		free()
		i++;
	}
	close(fd);
	return (0);
}
