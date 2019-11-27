#ifndef HOLBERTON_SHELL
#define HOLBERTON_SHELL

/**/
#define EXIT_CMD "exit"
#define ENV_CMD "env"
/**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**/


/*itte.c*/
void _itte();
/*_getline.c*/
ssize_t _getline(char **buf);
/*noItte.c*/
void _noItte(char *av);
/*_execute*/
void _execute(char **buff);
/*errors.c*/
void _fork_fail(char **buff);
/*_token*/
char **token(char *str, char **cmd, int *size);
/*helper_funcs*/
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(char *s1, char *s2);
unsigned int _strlen_const(const char *name);
unsigned int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_copyCmd(char *dest, char *src, const char *command, unsigned int dir_len, unsigned int cmd_len);




#endif