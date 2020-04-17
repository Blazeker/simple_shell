#include "shell.h"

/**
 * check_dir - execute directory command
 * @argv: direction pointer
 * @string: Pointer to string
 * @environ: double pointer
 * @av: command
 * @cmd: nro of line
 * @flag: know who call
 * @status: status_exit
 * Return: None
*/
int check_dir(char **argv, char *string, char **environ,
		  char *av[], int cmd, int flag, int status)
{
	struct stat stats;

	if (stat(argv[0], &stats) == 0)
	{
		if (S_ISDIR(stats.st_mode) == 0)
			status = execute_dir(argv, string, environ, av, cmd, flag);
		else
		{
			print_error(argv, av, cmd);
			if (write(2, "Permission denied\n", 18) < 0)
				return (127);
			return (126);
		}
	}
	else
	{
		print_error(argv, av, cmd);
		if (write(2, "not found\n", 10) < 0)
			return (127);
		return (127);
	}
	return (status);
}

/**
 * execute_dir - execute directory command
 * @argv: direction pointer
 * @string: Pointer to string
 * @environ: double pointer
 * @av: command
 * @cmd: nro of line
 * @flag: know who call
 * Return: None
*/
int execute_dir(char **argv, char *string, char **environ,
		 char *av[], int cmd, int flag)
{
	pid_t my_pid;
	char *aux;
	int j, status_exit = -1;

	if (flag == 1)
		aux = string;
	else
		aux = argv[0];
	my_pid = fork();
	if (my_pid == 0)
	{
		argv[0] = aux;
		for (j = 0; argv[j]; j++)
		{
			argv[j] = quotes_echo(argv[j], '\"');
		}
		if (execve(string, argv, environ) == -1)
		{
			execute_err(string, av, cmd);
			free_malloc(argv);
			free(string);
			exit(126); }
	}
	else if (my_pid > 0)
	{
		if (wait(&status_exit) < 0)
		{
			permission_err_ex(av, cmd, argv);
			return (2); }
	}
	else
	{
		permission_err_ex(av, cmd, argv);
		return (2); }
	return (status_exit / 255);
}
