/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:49 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/11 18:01:38 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	read_new_line(char *buffer, int count)
{
	while (*buffer != '\n')
	{
		ft_putchar(*buffer);
		buffer++;
		count++;
	}
	if (*buffer == '\n')
	{
		ft_putchar(*buffer);
		count++;
	}
	return (count);
}

static char	*read_file(int fd)
{
	static int	size_read;
	static int	count;
	static int	i;
	static char	*buffer;

	count = 0;
	if (!fd)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	size_read = read(fd, buffer, BUFFER_SIZE);
	if (size_read <= 0 || !size_read)
	{
		free(buffer);
		return (NULL);
	}
	while (count < (size_read - count))
	{
		count = read_new_line(buffer + count, count);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	if (!fd)
		return (NULL);
	buffer = read_file(fd);
	if (!buffer)
	{
		write (1, "NULL", 4);
		return (NULL);
	}
	return (buffer);
}
