NAME		= minishell
OBJ			= main utils signals \
				commands/commands \
				commands/echo \
				ms_line_executer ft_list_x_to_array heredoc\
				tokenizer/tk_tokenizer \
				tokenizer/tk_utils \
				tokenizer/tk_wordsplit \
				tokenizer/tk_name_tokens \
				tokenizer/tk_expander \
				tokenizer/tk_remove_quotes \
				environment/ev_sort_alfa \
				environment/ev_init_env \
				environment/ev_add_env \
				environment/ev_get_env \
				lexer/lexer \
				lexer/lexer_utils
OBJS		= $(addsuffix .o, $(addprefix obj/, ${OBJ}))
CC			= gcc
RM			= rm -f
HEADER		= -I headers/ 
RL_I		= -I $$HOME/.brew/opt/readline/include
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
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