#include "shell.h"

/**
 * free_malloc - free malloc
 * @argv: direction pointer
 * Return: None
 */
void free_malloc(char **argv)
{
	char **aux = argv;

	free(aux);
}

/**
 * create_malloc - free malloc
 * @size: size of string
 * Return: double pointer
 */
char **create_malloc(size_t size)
{
	char **argv;

	argv = malloc(sizeof(char *) * size);
	if (!argv)
		exit(0);
	return (argv);
}
