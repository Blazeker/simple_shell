#include "shell.h"

/**
* find_path - a function that gets the path
* @environ: pointer that locate a character.
* Return: pointer.
*/
char *find_path(char **environ)
{
	int i, j;
	char strpath[] = "PATH=";
	char buffer[1024], *extra = buffer;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] && j < 5; j++)
		{
			if (environ[i][j] != strpath[j])
				break;
			if (j == 4)
				extra = environ[i];
		}
	}
	while (*extra != '\0')
	{
		if (*extra == '=')
		{
			extra++;
			break;
		}
		extra++;
	}
	return (extra);
}

/**
 * check_path - run dir path
 * @value: direction pointer
 * @aux: direction PATH
 * @argv: direction double pointer
 * @string: command PATH
 * @environ: double pointer
 * @av: command
 * @cmd: nro of line
 * @copy_path: copy path
 * @status: status of exit
 * Return: dir path
*/
int check_path(char *aux, char *value, char **argv,
		   char *string, char **environ,
		   char *av[], int cmd, char *copy_path, int status)
{
	char *token, pwd[] = "./";
	struct stat stats;
	int bandera;

	_strcpy(copy_path, aux);
	bandera = 0;
	if (*copy_path == ':')
		bandera = 1;
	else if (string[0] == '.' && string[1] == '/')
		bandera = 2;
	token = strtok(copy_path, COLON);
	while (token != NULL)
	{
		if (bandera == 1)
			_strcat(value, pwd), _strcat(value, argv[0]);
		else if (bandera == 2)
			_strcpy(value, argv[0]);
		else
		{
			_strcpy(value, token);
			_strcat(value, SLASH), _strcat(value, argv[0]);
		}
		bandera = 0;
		if (stat(value, &stats) == 0)
		{
			status = execute_dir(argv, value, environ, av, cmd, 2);
			break; }
		token = strtok(NULL, COLON);
	}
	if (token == NULL)
	{
		if (_strcmp(argv[0], "exit") != 0)
		{
			print_error(argv, av, cmd);
			if (write(2, "not found\n", 10) < 0)
				exit(127);
			return (127);
		}
	}
	return (status);
}

/**
 * execute_path - find command path
 * @argv: direction pointer
 * @string: function PATH
 * @environ: double pointer
 * @av: command
 * @cmd: nro of line
 * @dir_path: dir path
 * @status: status of exit
 * Return: None
*/
int execute_path(char **argv, char *string, char **environ,
		char *av[], int cmd, char *dir_path, int status)
{
	char *value = NULL, *copy_path = NULL;

	value = malloc(sizeof(char) * _strlen(dir_path) + _strlen(string));
	if (value == NULL)
		exit(90);
	copy_path = malloc(sizeof(char) * _strlen(dir_path) + _strlen(string));
	if (copy_path == NULL)
		exit(90);
	status = check_path(dir_path, value, argv, string, environ,
			av, cmd, copy_path, status);
	free(value);
	free(copy_path);
	return (status);
}
