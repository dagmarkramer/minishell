NAME		= minishell
COMMANDS	= cd echo env exit export pwd unset utils
TOKENIZER	= tokenizer utils wordsplit name_tokens expander remove_quotes
ENVIRONMENT	= sort_alfa init_env add_env get_env
EXECUTE		= parser execute exe_buildin exe_utils fd_redir
OBJ			= main utils signals heredoc lst_to_array wildcard_bonus \
				$(addprefix commands/ms_, ${COMMANDS}) \
				$(addprefix tokenizer/tk_, ${TOKENIZER}) \
				$(addprefix environment/ev_, ${ENVIRONMENT}) \
				$(addprefix execute/, ${EXECUTE}) \
				lexer/lexer \
				ms_line_executer
OBJS		= $(addsuffix .o, $(addprefix obj/, ${OBJ}))
CC			= gcc
RM			= rm -f
HEADER		= -I headers/ 
RL_I		= -I $$HOME/.brew/opt/readline/include
CFLAGS		= -Wall -Wextra -Werror
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
