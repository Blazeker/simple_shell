#include "shell.h"

/**
 * check_dpoints - checks for double points
 * @aux: pointer aux
 * Return: 1 if find a double point and 0 if not
 */

int check_dpoints(char *aux)
{
	if ((aux[0] == '.' && aux[1] == '.' && aux[2] == '\0'))
		return (1);
	else
		return (0);
}


/**
 * validate_com - validate command
 * @aux: unused.
 * Return: 0 is ok and -1 ko
 */
int validate_com(char *aux)
{
	if (*aux == '\n' || *aux == ' ' || *aux == '\t' ||
		(*aux == '.' && aux[1] == '\n'))
		return (-1);
	return (0);
}


/**
* _isdigit - evaluate if the variable is a digit or not.
* @c: input variable.
* Return: Always 0.
*/
int _isdigit(char *c)
{
	int i;

	for (i = 0; c[i]; i++)
	{
		if (c[i] < 48 || c[i] > 57)
			return (0);
	}
	return (1);
}
