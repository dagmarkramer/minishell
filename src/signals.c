#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "minishell.h"

// ctrl + C SIGINT
// ctrl + \ SIGQUIT

void	newline_handler(int signum)
{
	// write(1, "\b\b  \b\b", 6);
	write(1, "\n", 1);
	rl_on_new_line();
	// rl_replace_line();
	rl_redisplay();
	g_global = 1;
	(void)signum;
	// signal(SIGINT, newline_handler);
}

// need to remove with backspaceprint (del??)
void	nothing_handler(int signum)
{
	// write(1, "\b\b  \b\b", 6);
	g_global = 1;
	(void)signum;
	// signal(SIGQUIT, nothing_handler);
}

void	ms_set_terms(void)
{
	struct termios	term;

	term.c_lflag = ECHOCTL;
	// new_term.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &term);
}

int signals(void)
{
	// struct sigaction	newline;
	// struct sigaction	nothing;

	ms_set_terms();
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

