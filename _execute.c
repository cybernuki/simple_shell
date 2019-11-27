#include "holberton.h"

void _execute(char **buff)
{
    pid_t pid;
    char **cmd = NULL;
    int size = 0;

    pid = fork();

    if (pid == -1)
        _fork_fail(buff);
    if (pid == 0)
    {
        cmd = token(*buff, cmd, &size);
        if (execve(*buff, cmd, NULL) == -1)
            perror("./shell");

    }
    else
    {
        wait(NULL);
        free(cmd);
        free(*buff);
        cmd = NULL;
    }
}