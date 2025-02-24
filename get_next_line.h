/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:17:44 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/24 13:13:43 by alvera-v         ###   ########.fr       */
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
ssize_t		read(int fd, void *buf, size_t count);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmeb, size_t size);
char		*check_new_line(char *buffer);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*update_line_read(char *str, char *buffer);
size_t		ft_strlen(char const *s);
char		*free_line(char *str);
void		*ft_memcpy(void *dest, const void *src, size_t n);

#endif
