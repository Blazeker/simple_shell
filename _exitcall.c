#include "shell.h"

/**
* exitcall - exit function
* @argv: Pointer to free
* @string: pointer to free
* @status: status_exit
* @av: name of the program
* @cmd: line run
* Return: pointer.
*/
int exitcall(char **argv, char *string, int status,
				char *av[], int cmd)
{
	int n;

	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] == NULL)
		{
			free_malloc(argv), free(string);
			exit(status);
		}
		else
		{
			n = _atoi(argv[1]);
			if (n < 0 || _isdigit(argv[1]) == 0)
			{
				execute_err(string, av, cmd);
				if (write(2, argv[1], _strlen(argv[1])) < 0)
					exit(127);
				if (write(2, "\n", 1) < 0)
					exit(127);
				free_malloc(argv);
				free(string);
				return (2);
			}
			else
			{
				free_malloc(argv), free(string);
				exit(n);
			}
		}
	}
	else
	{
		free_malloc(argv);
		free(string);
		return (status);
	}
}
