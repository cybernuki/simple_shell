#include "holberton.h"

void searchDir(char **cmd, char **env)
{
    char *all_dir = NULL;

    all_dir = test_env(cmd[0], env);
    if (all_dir)
    {
        if (execve(all_dir, cmd, env) == -1)
        {
            perror("./shell");
        }
        free(all_dir);
    }
}