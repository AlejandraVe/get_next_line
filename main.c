/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:02:05 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/24 13:19:19 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*next_line;
	int		i;

	i = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	printf("%s", "hola");
	while ((next_line = get_next_line(fd)) && next_line != NULL)
	{
		printf("[%d] %s", i++, next_line);
		free (next_line);
	}
	close (fd);
	return (0);
}
