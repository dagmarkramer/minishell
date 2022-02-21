#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

// ctrl + C SIGINT
// ctrl + \ SIGQUIT

void	newline_handler(int signum)
{
	// write(1, "\b\b  \b\b", 6);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)signum;
	// signal(SIGINT, newline_handler);
}

// need to remove with backspaceprint (del??)
void	nothing_handler(int signum)
{
	// write(1, "\b\b  \b\b", 6);
	(void)signum;
	rl_redisplay();
	// signal(SIGQUIT, nothing_handler);
}

int signals(void)
{
	// struct sigaction	newline;
	// struct sigaction	nothing;

	// newline.sa_flags = 0;
	// nothing.sa_flags = 0;
	// newline.sa_handler = newline_handler;
	// nothing.sa_handler = nothing_handler;
	// sigaction(SIGINT, &newline, 0);
	// sigaction(SIGQUIT, &nothing, 0);


	signal(SIGINT, newline_handler);
	signal(SIGQUIT, nothing_handler);
	return (0);
}

