#include "shell.h"

/**
 * move_to_position - move the string to a specific position
 * @aux: String pointer
 * Return: a pointer
 */

char *move_to_position(char *aux)
{
	while (*aux != '\0')
	{
		if (*aux != ' ' && *aux != '\t')
			break;
		aux++;
	}
	return (aux);
}
