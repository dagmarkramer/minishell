NAME := pipex
HEADERFILES := pipex.h
SRCFILES := pipex.c utils.c
OBJFILES := $(SRCFILES:%.c=%.o)
LIBFT := libft/libft.a
CFLAGS ?= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJFILES)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -Llibft -lft -o $@ $^

%.o: %.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJFILES)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
