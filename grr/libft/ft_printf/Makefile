# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkramer <dkramer@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/10 09:41:33 by dkramer       #+#    #+#                  #
#    Updated: 2021/03/07 10:39:39 by dkramer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINTF_SOURCES = ft_printf.c ft_xpformat.c ft_diuformat.c ft_csformat.c\
	ft_width.c ft_convert.c

PRINTF_OBJECTS = $(PRINTF_SOURCES:%.c=%.o)

# LIBFT		=	libft/libft.a

CC = gcc

HEADERS = libftprintf.h

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(PRINTF_OBJECTS)
			# $(MAKE) -C libft
			# cp $(LIBFT) $(NAME)
			ar -rcs $(NAME) $(PRINTF_OBJECTS)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	# $(MAKE) -C libft clean
	rm -f $(PRINTF_OBJECTS)

fclean: clean
	# $(MAKE) -C libft  fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
