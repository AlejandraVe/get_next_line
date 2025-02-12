/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:49 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/12 13:48:00 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	print_new_line(char *buffer, int count)
{
	if (buffer[count] != '\n')
	{
		ft_putchar(buffer[count]);
	}
	else if (buffer[count] == '\n')
	{
		ft_putchar(buffer[count]);
	}
	count++;
	return (count);
}

static char	*read_file(int fd)
{
	static int		size_read;
	static int		count;
	char			*buffer;

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
	while (count < size_read)
		count = print_new_line(buffer, count);
	if ((*buffer + count) == '\0')
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
