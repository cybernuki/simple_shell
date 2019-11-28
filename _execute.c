#include "holberton.h"

void _execute(char **buff, char **env)
{
    pid_t pid;
    char **cmd = NULL;
    int size = 0;
    struct stat Stat;

    pid = fork();
    if (pid < 0)
        perror("Fail"), exit(0);
    if (pid == 0)
    {
        cmd = token(*buff, cmd, &size);
        if (stat(cmd[0], &Stat) == 0)
        {
            if (execve(cmd[0], cmd, env) == -1)
              perror("./shell");
        }
        else
        {
            searchDir(cmd, env);
        }
    }
    else
    {
        wait(NULL);
        if (cmd)
          free(cmd);
        free(*buff);
        cmd = NULL;
    }
}