#include "shell.h"
/**
 * _print_promt - print $ simbol in the command prompt
 * Return: Nothing
 */
void _print_promt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		if (write(STDOUT_FILENO, "$ ", 2) < 0)
			exit(EXIT_FAILURE);
	}
}
