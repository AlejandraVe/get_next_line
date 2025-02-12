# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvera-v <alvera-v@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 13:43:46 by alvera-v          #+#    #+#              #
#    Updated: 2025/02/12 13:46:27 by alvera-v         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SOURCES =	get_next_line.c \
			get_next_line_utils.c \
			get_next_line.h

MY_OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

all: $(NAME)

$(NAME):
		cc -c $(CFLAGS) $(SOURCES)
		ar rcs $(NAME) $(MY_OBJECTS)

clean:
		rm -f $(MY_OBJECTS)

fclean:
		rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
