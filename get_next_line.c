/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:25:49 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/26 16:52:43 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_line(char *str)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	new_line = malloc(sizeof(char *) * (i + 1));
	if (!new_line)
		return (NULL);
	new_line[i] = '\0';
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		new_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_line[i] = '\n';
	new_line[i + 1] = '\0';
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
	updated = malloc(sizeof(char *) * (ft_strlen(str) - i + 1));
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
	static char	*lines;
	char		*buffer;
	int			size_read;

	size_read = 7;
	if (fd < 0)
		return (NULL);
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!(ft_strchr(lines, '\n')) && (size_read != 0))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size_read] = '\0';
		lines = ft_strjoin(lines, buffer);
	}
	free(buffer);
	buffer = check_line(lines);
	lines = update_line(lines);
	return (buffer);
}
