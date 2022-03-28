NAME		= minishell
OBJ			= main utils signals commands \
				tokenizer/tk_tokenizer \
				tokenizer/tk_utils \
				tokenizer/tk_wordsplit \
				environment/sort_alfa \
				tokenizer/tk_name_tokens \
				tokenizer/tk_expander \
				environment/ms_init_env \
				environment/ms_get_env
OBJS		= $(addsuffix .o, $(addprefix obj/, ${OBJ}))
CC			= gcc
RM			= rm -f
HEADER		= -I headers/ 
RL_I		= -I $$HOME/.brew/opt/readline/include
CFLAGS		= -Wall -Wextra -g #-fsanitize=address#-Werror
LFLAGS		= -lreadline -lncurses -L $$HOME/.brew/opt/readline/lib
LIBFT		= Libft/libft.a

all:		${NAME}

obj/%.o:	src/%.c
				@mkdir -p $(dir $@)
				$(CC) $(CFLAGS) $(RL_I) $(HEADER) -c -o $@ $<

clean:
				@${RM} ${OBJS} \
				$(info ************  minishell Clean)

cleanft:
				@${MAKE} clean -C Libft --no-print-directory

fclean:		clean
				@${MAKE} fclean -C Libft --no-print-directory
				@${RM} ${NAME}
				$(info ************  minishell Removed)

re:			fclean all

${NAME}:	${OBJS}
				@${MAKE} bonus -C Libft --no-print-directory
				@${CC} $(OBJS) $(LIBFT) $(CFLAGS) -o $@ $(LFLAGS) 
				$(info ************  minishell Ready!)

.PHONY: all clean fclean re cleanft