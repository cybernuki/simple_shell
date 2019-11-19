#ifndef HOLBERTON_H
#define HOLBERTON_H

/* MACROS SETSIS */

#define PROMPT "$EquipoDinamita "

/* Library */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

/* Functions */

char *_getline();
void exec_ve(char *argv[]);
char **array_to_strok(char *str, char **commands, int *size);
void promptMessage();
char *_strncpy(char *dest, char *src, int n);


#endif