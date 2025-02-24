/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:49 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/24 13:32:37 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_new_line(char *str)
{
	char	*new_line;
	int		i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	new_line = ft_calloc(i + 1, sizeof(char *));
	if (!new_line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		new_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*free_line(char *str)
{
	char	*new;
	char	*position;
	int		i;

	i = 0;
	position = ft_strchr(str, '\n');
	if (!position)
	{
		free(str);
		return (NULL);
	}
	position++;
	new = ft_calloc(ft_strlen(position) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (*position != '\0')
	{
		new[i] = *position;
		position++;
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*line_read;
	char		*buffer;
	char		*line;
	int			size_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	line_read = NULL;
	size_read = 1;
	while (!ft_strchr(line_read, '\n') && 0 < size_read)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read < 0)
		{
			free(line_read);
			line_read = NULL;
			return (NULL);
		}
		buffer[size_read] = '\0';
		line_read = update_line_read(line_read, buffer);
		if (!line_read)
			return (NULL);
	}
	line = check_new_line(line_read);
	line_read = free_line(line_read);
	return (line);
}

char	*update_line_read(char *str, char *buffer)
{
	char	*updated;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	if (!str)
		return (NULL);
	updated = ft_strjoin(str, buffer);
	free(str);
	return (updated);
}
