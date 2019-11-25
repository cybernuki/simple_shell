#ifndef HOLBERTON_H
#define HOLBERTON_H

/* MACROS SETSIS */

#define PROMPT "$EquipoBuenaOndaDinamita "
#define EXIT_COMMAND "exit"
#define ENV_COMMAND "env"
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
int _strcmp(char *s1, char *s2);
unsigned int _strlen_const(const char *name);
char *test_env(const char *command);
char *_copyCmd(char *dest, char *src, const char *command, unsigned int dir_len, unsigned int cmd_len);
void printEnv(char *env[]);

#endif