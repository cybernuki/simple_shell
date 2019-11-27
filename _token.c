#include "holberton.h"

char **token(char *str, char **commands, int *size)
{
    char *token;

    *size = 0;
    commands = malloc(sizeof(commands));
    if (!commands)
        return (NULL);

    token = strtok(str, " \n");
    commands[*size] = token;
    while (token) 
   {
        (*size) += 1;
        token = strtok(NULL, " \n");
        commands = (char **)_realloc(commands, (*size) * sizeof(commands),(*size + 1) * sizeof(commands));
        commands[*size] = token;
 
   }
   
    return (commands);
}