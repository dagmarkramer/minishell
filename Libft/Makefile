# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dkramer <dkramer@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/09 09:51:57 by dkramer       #+#    #+#                  #
#    Updated: 2022/04/07 15:58:51 by obult         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c\
 ./ft_isprint.c ./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_itoa.c \
 ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c \
./ft_split.c ./ft_strjoin.c ./ft_strmapi.c ./ft_strtrim.c \
./ft_substr.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c \
./ft_memmove.c ./ft_memset.c ./ft_strchr.c ./ft_strdup.c ./ft_strlcat.c \
./ft_strlcpy.c ./ft_strlen.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c \
./ft_tolower.c ./ft_toupper.c ./ft_strrev.c \
$(ADDITIONS)

ADDITIONS	= gnl.c

BONUS	= ./ft_lstadd_back.c ./ft_lstadd_front.c ./ft_lstclear.c \
./ft_lstdelone.c ./ft_lstiter.c ./ft_lstlast.c ./ft_lstmap.c ./ft_lstnew.c \
./ft_lstsize.c

REG_OBJS	= ${SRCS:.c=.o}

BON_OBJS	= ${BONUS:.c=.o}

CC		= gcc

RM		= rm -f

HEADER	= -I

CFLAGS	= -Wall -Werror -Wextra

LIB		= ar -rsc

ifdef WITH_BONUS
OBJS = ${REG_OBJS} ${BON_OBJS}
else
OBJS = ${REG_OBJS}
endif

all:		${NAME}

.c.o:
				@${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

clean:
				@${RM} ${REG_OBJS} ${BON_OBJS} \
				$(info [][][][][][]  Libft clean)

fclean:		clean
				@${RM} ${NAME} \
				$(info [][][][][][]  libft.a removed)

re:			fclean all

${NAME}:	${OBJS}
				@${LIB} $@ $^ \
				$(info [][][][][][]  Library created)

bonus:
				@${MAKE} WITH_BONUS=1 all
				$(info [][][][][][]  Library bonus)

.PHONY: all clean fclean re bonus
