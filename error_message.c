#include "holberton.h"

void commandNull(char *buff)
{
    free(buff);
    exit(EXIT_SUCCESS);
}
/**
 * fork_fail - fork fail function
 * 
 */
void fork_fail(void)
{
    perror("Error:");
    exit(0);
}

void _EOF(char *buf)
{
    if (isatty(STDIN_FILENO))
        write(STDIN_FILENO, "\n", 1);
    free(buf);
    exit(EXIT_FAILURE);
}

void _exit_end(char *buf, char **commands)
{
    free(buf);
    free(commands);
    exit(EXIT_SUCCESS);
}

void _print_env(char *buffer, char **commands, char **env)
{
    free(buffer);
    free(commands);
    printEnv(env);
    exit(EXIT_SUCCESS);
}

void free_commands_buff(char *buffer, char **commands)
{
    free(buffer);
    free(commands);
}