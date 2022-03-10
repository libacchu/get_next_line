/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: libacchu <libacchu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 11:12:10 by libacchu          #+#    #+#             */
/*   Updated: 2022/03/10 23:21:59 by libacchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

	// printf("Enter number of lines: ");
	// scanf("%d", &lines);
int	main(void)
{
	int		fd;
	int		i;
	int		lines;
	char	*str;

	fd = open("./test", O_RDONLY);
	lines = 2;
	i = 1;
	while (i <= lines)
	{
		str = get_next_line(fd);
		printf("\nget next line %d 	= *%s*\n", i, str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}
