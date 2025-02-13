/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:49 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/13 17:23:45 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new_line(char *buffer, int count)
{
	char	*new_line;
	int		size_of_line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i + count] != '\n')
		i++;
	new_line = ft_calloc(i + 1, sizeof(char));
	if (!new_line)
		free(new_line);
	j = 0;
	while (j <= i)
	{
		new_line[j] = buffer[count];
		ft_putchar(new_line[j]);
		j++;
		count++;
	}
	free(new_line);
	return (count);
}

static char	*read_file(int fd)
{
	static int		size_read;
	static int		count;
	char			*buffer;

	count = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	size_read = read(fd, buffer, BUFFER_SIZE);
	if (size_read <= 0 || !size_read)
	{
		free(buffer);
		return (NULL);
	}
	while (count < size_read)
		count = check_new_line(buffer, count);
	if ((buffer[count + 1]) == '\0')
	{
		write (1, "NULL", 4);
		return (NULL);
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
