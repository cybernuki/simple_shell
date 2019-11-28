#include "holberton.h"

void searchDir(char **cmd, char **env)
{
    char *all_dir = NULL;
    all_dir = test_env(cmd[0], env);
    if (execve(all_dir, cmd, env) == -1)
    {
           perror("./shell");
    }
    if(all_dir)
      free(all_dir);
}