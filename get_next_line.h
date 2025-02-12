/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:01 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/12 13:46:57 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char		*get_next_line(int fd);
int			print_new_line(char *buffer, int count);
void		ft_putstr(char *s);
void		ft_putchar(char c);
ssize_t		read(int fd, void *buf, size_t count);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmeb, size_t size);

#endif
