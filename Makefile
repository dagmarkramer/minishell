NAME		= minishell
OBJ			= main utils signals commands
OBJS		= $(addsuffix .o, $(addprefix obj/, ${OBJ}))
CC			= gcc
RM			= rm -f
<<<<<<< HEAD
HEADER		= -I headers/ 
RL_I		= -I $$HOME/.brew/opt/readline/include
CFLAGS		= -Wall -Wextra #-Werror#-g fsanitize=address
LFLAGS		= -lreadline -L $$HOME/.brew/opt/readline/lib
=======
HEADER		= -I headers/
CFLAGS		= -g -fsanitize=address
EFLAGS		= -lreadline -lncurses
>>>>>>> 3b534b8286fb884f3edd2c0564f7848149ff7353

all:		${NAME}

obj/%.o:	src/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) $(RL_I) $(HEADER) -c -o $@ $<

clean:
				@${RM} ${OBJS} \
				$(info ************  minishell Clean)

libclean:
				@${MAKE} clean -C Libft --no-print-directory

fclean:		clean
				@${RM} ${NAME}
				$(info ************  minishell Removed)
				${MAKE} fclean -C Libft --no-print-directory

re:			fclean all

${NAME}:	${OBJS} Libft/libft.a
				@${CC} $(OBJS) Libft/libft.a $(CFLAGS) -o $@ $(LFLAGS) 
				$(info ************  minishell Ready!)

Libft/libft.a:
				@${MAKE} -C Libft --no-print-directory

.PHONY: all clean fclean re