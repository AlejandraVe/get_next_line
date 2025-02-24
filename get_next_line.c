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
	new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		new_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new_line[i] = '\n';
	new_line[i + 1] = '\0';
	return (new_line);
}

/*char	*free_line(char *str)
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
}*/

char	*get_next_line(int fd)
{
	static char	*line_read;
	char		*buffer;
	char		*line;
	int			size_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_read = NULL;
	size_read = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(line_read, '\n') && size_read != 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read < 0)
		{
			free(line_read);
			return (NULL);
		}
		buffer[size_read] = '\0';
		line_read = ft_strjoin(line_read, buffer);
	}
	free(line_read);
	buffer = check_new_line(line_read);
	line_read = update_line(line_read);
	return (buffer);
}

char	*update_line(char *str)
{
	char	*updated;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	if (!str)
	{
		free(str);
		return (NULL);
	}
	i += (stored[i] == '\n');
	updated = (char *) malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!updated)
		return (NULL);
	while (str[i + j])
	{
		updated[j] = str[i + j];
		j++;
	}
	updated[j] = '\0';
	free(str);
	return (updated);
}
