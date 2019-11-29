#include "holberton.h"
/**
 * gcc -Wall -Werror -Wextra -pedantic *.c -o hsh && ./hsh
 */
int main(int ac, char **av, char **env)
{
    if (ac == 1)
    {
	    if (isatty(STDIN_FILENO))
		    _itte(env);
	    else
		    _noItte(*av, env);
    }
/*        isatty(STDIN_FILENO) ? _itte(env) : _noItte(*av, env);
 */  else
        return (2);
    return (0);
}
