/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:50 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/24 12:59:25 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*temp;

	temp = malloc(nmeb * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, nmeb * size);
	return (temp);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}

char	*use_buffer(char *buffer, int fd)
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

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1) + 1;
	len_s2 = ft_strlen(s2);
	ret = malloc(len_s1 + len_s2);
	if (!ret)
		return (NULL);
	ft_memcpy((char *)ret, (const char *)s1, len_s1);
	ft_memcpy((char *)ret, s2, len_s1 + len_s2);
	return (ret);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
