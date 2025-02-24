/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:50 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/24 18:34:47 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*use_buffer(char *buffer, int fd)
{
	static int	size_read;
	static int	count;

	count = 0;
	size_read = read(fd, buffer, BUFFER_SIZE);
	if (size_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[size_read] = '\0';
	while (count <= size_read)
	{
		count = check_new_line(buffer, count);
		if ((buffer[count + 1]) == '\0')
		{
			write (1, "NULL", 4);
			return (NULL);
		}
	}
	if (count == BUFFER_SIZE)
	{
		buffer = get_next_line(fd);
	}
	return (buffer);
}*/
size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret = ft_join(ret, s1, s2);
	free(s1);
	return (ret);
}

char	*ft_join(char *dest, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
