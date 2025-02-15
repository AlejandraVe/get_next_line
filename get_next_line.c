/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:49 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/15 16:06:12 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_new_line(char *buffer, int count)
{
	char	*original_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[count + j] != '\n')
		j++;
	original_line = ft_calloc(j + 1, sizeof(char *));
	if (!original_line)
		free(original_line);
	while (i <= j)
	{
		original_line[i] = buffer[count];
		ft_putchar(original_line[i]);
		if (original_line[i] == '\n')
		{
			free(original_line);
			break;
		}
		i++;
		count++;
	}
	count += 1;
	return (count);
}

static char	*read_file(int fd)
{
	static int		size_read;
	static int		count;
	char			*buffer;

	count = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	size_read = read(fd, buffer, BUFFER_SIZE);
	if (size_read <= 0 || !size_read)
	{
		free(buffer);
		return (NULL);
	}
	while (count <= size_read)
	{
		count = check_new_line(buffer, count);
		if (count == BUFFER_SIZE)
			free(buffer);
		if ((buffer[count + 1]) == '\0')
		{
			write (1, "NULL", 4);
			return (NULL);
		}
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	if (!fd)
		return (NULL);
	buffer = read_file(fd);
	return (buffer);
}
