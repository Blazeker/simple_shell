#include "shell.h"

/**
 * main - basic shell
 * @argc: unused.
 * @av: name of file.
 * @environ: variables.
 * Return: prints in screen $ and received commands
 */
int main(__attribute__((unused)) int argc, char *av[], char **environ)
{
	char **argv, *dir_path, *string, *aux;
	size_t size = 0;
	ssize_t bytes_read = 0;
	int cmd = 0, status = 0;

	dir_path = find_path(environ);
	while (1)
	{
		string = NULL, aux = NULL;
		_print_promt();
		bytes_read = getline(&string, &size, stdin);
		cmd++;
		if (bytes_read == EOF)
		{
			free(string);
			break;
		}
		aux = string;
		aux = move_to_position(aux);
		if (validate_com(aux) == -1)
		{
			free(string);
			continue;
		}
		argv = create_malloc(size);
		split_aux(argv, aux);
		argv[0] = quotes_echo(argv[0], '\"');
		aux = quotes_echo(aux, '\"');
		if (find_slash('/', aux) == 1 || check_dpoints(aux) == 1)
			permission_err(aux, av, cmd), status = 126;
		else
		{
			if (_strchr(aux) == 0)
				status = check_dir(argv, aux, environ, av, cmd, 1, status);
			else
				status = execute_path(argv, aux, environ, av, cmd, dir_path, status);
		}
		status = exitcall(argv, string, status, av, cmd);
	}
	return (status);
}
