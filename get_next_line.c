/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:49 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/24 18:24:29 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*check_new_line(char *str)
{
	char	*new_line;
	int		i;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*update_line(char *str)
{
	char	*updated;
	int		i;
	int		j;

	i = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i += (str[i] == '\n');
	updated = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!updated)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		updated[j] = str[i + j];
		j++;
	}
	updated[j] = '\0';
	free(str);
	return (updated);
}

char	*get_next_line(int fd)
{
	static char	*line_read;
	char		*buffer;
	int			size_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	size_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(line_read, '\n')) && (size_read != 0))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size_read] = '\0';
		line_read = ft_strjoin(line_read, buffer);
	}
	free(buffer);
	buffer = check_new_line(line_read);
	line_read = update_line(line_read);
	return (buffer);
}
