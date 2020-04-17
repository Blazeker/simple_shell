#include "shell.h"

/**
 * split_aux - get flags to command
 * @argv: direction pointer
 * @string: Pointer to string
 * Return: None
 */
void split_aux(char **argv, char *string)
{
	char **arguments = argv;
	int i = 0;
	char delimit[] = " \t";
	char *token = strtok(string, delimit);

	if (_strcmp(token, "/bin/echo") == 0 || _strcmp(token, "echo") == 0)
	{
		while (token != NULL)
		{
			arguments[i] = token;
			if (i == 0)
				token = strtok(NULL, " ");
			else
			{
				if (*token == '\"')
					token = strtok(NULL, "\"");
				else
					token = strtok(NULL, " ");
			}
			i++;
		}
	}
	else
	{
		while (token != NULL)
		{
			arguments[i] = token;
			token = strtok(NULL, delimit);
			i++;
		}
	}
	arguments[i] = NULL;
	arguments[i - 1] = strtok(arguments[i - 1], NEW_LINE);
}
