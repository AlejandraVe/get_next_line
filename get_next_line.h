/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:17:44 by alvera-v          #+#    #+#             */
/*   Updated: 2025/02/26 16:25:43 by alvera-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

char		*get_next_line(int fd);
ssize_t		read(int fd, void *buf, size_t count);
char		*check_line(char *buffer);
char		*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *s);
char		*update_line(char *str);
char		*ft_join_str(char *dest, char *s1, char *s2);

#endif
