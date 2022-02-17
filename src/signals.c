#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

// ctrl + C SIGINT
// ctrl + \ SIGQUIT

void    newline_handler(int signum)
{
    printf("\n");
    (void)signum;
}

// need to remove with backspaceprint (del??)
void    nothing_handler(int signum)
{
    write(1, "\b\b", 2);
    write(1, "  ", 2);
    write(1, "\b\b", 2);
    (void)signum;
}

int signals(void)
{
    signal(SIGINT, newline_handler);
    signal(SIGQUIT, nothing_handler);
    return (0);
}
