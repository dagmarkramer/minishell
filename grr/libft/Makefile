# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkramer <dkramer@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/09 09:51:57 by dkramer       #+#    #+#                  #
#    Updated: 2021/10/10 13:10:27 by dkramer       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT_SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
		ft_split.c ft_strchr.c\
		ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
		ft_nrofdigits.c ft_itoa_base.c ft_putchar.c ft_strrev.c\
		get_next_line/get_next_line_utils.c get_next_line/get_next_line.c\

LIBFT_OBJECTS = $(LIBFT_SOURCES:%.c=%.o)

PRINTF		=	ft_printf/libftprintf.a

BONUS_SOURCES = ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstiter.c\
				ft_lstadd_back.c ft_lstadd_front.c\
				ft_lstdelone.c ft_lstclear.c ft_lstmap.c

BONUS_OBJECTS = $(BONUS_SOURCES:%.c=%.o)

CC = gcc

HEADERS = libft.h

ifdef WITH_BONUSFUNCTIONS
OBJECTS = $(LIBFT_OBJECTS) $(BONUS_OBJECTS)
else
OBJECTS = $(LIBFT_OBJECTS)
endif

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ft_printf
	cp $(PRINTF) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUSFUNCTIONS=1 all

clean:
	$(MAKE) -C ft_printf clean
	rm -f $(LIBFT_OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(MAKE) -C ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
