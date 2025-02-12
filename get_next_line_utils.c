/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:26:50 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/12 13:49:01 by alvera-v         ###   ########.fr       */
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
