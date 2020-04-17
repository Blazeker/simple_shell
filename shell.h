#ifndef SHELL_H
#define SHELL_H

/* Define macros */
#define NEW_LINE "\n"
#define SLASH "/"
#define COLON ":"
/*-------------------------------------------------------*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

/* String Functions */
int _strlen(char *s);
int _strchr(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
void _itos(long int num, char *str, int cont, int sign);
char *quotes_echo(char *s, char c);
int find_slash(char c, char *str);
char *move_to_position(char *aux);
int check_dpoints(char *aux);
/*-------------------------------------------------------*/

/* Directory Functions */
int execute_dir(char **argv, char *string, char **environ,
				char *av[], int cmd, int flag);
int check_dir(char **argv, char *string, char **environ,
			char *av[], int cmd, int flag, int status);
/*-------------------------------------------------------*/

/* Path Functions */
int execute_path(char **argv, char *string, char **environ,
				char *av[], int cmd, char *dir_path, int status);
int check_path(char *aux, char *value, char **argv,
			char *string, char **environ, char *av[],
			int cmd, char *copy_path, int status);
char *find_path(char **environ);
/*-------------------------------------------------------*/

/* Errors */
void print_error(char **argv, char *av[], int cmd);
void execute_err(char *string, char *av[], int cmd);
void permission_err(char *string, char *av[], int cmd);
void permission_err_ex(char *av[], int cmd, char **argv);
/*-------------------------------------------------------*/

/* Mallocs */
char **create_malloc(size_t size);
void free_malloc(char **argv);
/*-------------------------------------------------------*/

/* Exit */
int exitcall(char **argv, char *string, int status,
				char *av[], int cmd);
/*-------------------------------------------------------*/

/* Other Functions */
void split_aux(char **argv, char *string);
int validate_com(char *aux);
int _isdigit(char *c);
void _print_promt(void);
/*-------------------------------------------------------*/

#endif
