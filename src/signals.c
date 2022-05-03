#include "minishell.h"

static void	newline_handler(int signum)
{
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)signum;
}

static void	nothing_handler(int signum)
{
	(void)signum;
	rl_redisplay();
}

static void	single_newline_handler(int signum)
{
	(void)signum;
	write(1, "\n", 1);
}

void	ms_parenting_signals(void)
{
	signal(SIGINT, single_newline_handler);
}

void	ms_signals(void)
{
	rl_catch_signals = 0;
	signal(SIGINT, newline_handler);
	signal(SIGQUIT, nothing_handler);
}
