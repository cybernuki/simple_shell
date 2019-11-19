#include "holberton.h"
/**
 *
 */
char **array_to_strok(char *str, char **commands, int *size)
{
    char *token;

    *size = 0;
    commands = malloc(sizeof(commands));
    if (!commands)
        return (NULL);

    token = strtok(str, " ");
    commands[*size] = token;
    
    while (token)
    {
        (*size) += 1;
        token = strtok(NULL, " ");
        commands = (char **)realloc(commands, (*size + 1) * sizeof(commands));
        commands[*size] = token;
    }
    return (commands);
}
