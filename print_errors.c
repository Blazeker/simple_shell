#include "shell.h"

/**
* execute_err - show error
* @string: show argument and length
* @av: name of the program
* @cmd: line run
* Return: pointer.
*/
void execute_err(char *string, char *av[], int cmd)
{
	char com_num[1024];

	_itos(cmd, com_num, 0, 1);
	if (write(2, av[0], _strlen(av[0])) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
	if (write(2, com_num, _strlen(com_num)) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
	if (write(2, string, _strlen(string)) < 0)
		exit(127);
	if (_strcmp(string, "exit") == 0)
	{
		if (write(2, ": Illegal number: ", 18) < 0)
			exit(127);
	}
	else
	{
		if (write(2, ": not found\n", 12) < 0)
			exit(127);
	}
}
/**
 * print_error - print errors
 * @argv: arguments pointer
 * @av: main arguments pointer
 * @cmd: integer number of commands
 * Return: dir path
*/
void print_error(char **argv, char *av[], int cmd)
{
	char com_num[1024];

	_itos(cmd, com_num, 0, 1);
	if (write(2, av[0], _strlen(av[0])) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
	if (write(2, com_num, _strlen(com_num)) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
	if (write(2, argv[0], _strlen(argv[0])) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
}

/**
* permission_err - show error
* @string: show argument and length
* @av: name of the program
* @cmd: line run
* Return: pointer.
*/
void permission_err(char *string, char *av[], int cmd)
{
	char com_num[1024];

	_itos(cmd, com_num, 0, 1);
	if (write(2, av[0], _strlen(av[0])) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
	if (write(2, com_num, _strlen(com_num)) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
	if (write(2, string, _strlen(string)) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
	if (write(2, "Permission denied\n", 19) < 0)
		exit(127);
}

/**
* permission_err_ex - show execute permission errors
* @av: name of the program
* @cmd: line run
* @argv: double pointer
* Return: pointer.
*/
void permission_err_ex(char *av[], int cmd, char **argv)
{
	char com_num[1024];

	_itos(cmd, com_num, 0, 1);
	if (write(2, av[0], _strlen(av[0])) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
	if (write(2, com_num, _strlen(com_num)) < 0)
		exit(127);
	if (write(2, ": ", 2) < 0)
		exit(127);
	perror(argv[0]);
}
