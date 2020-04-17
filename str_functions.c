#include "shell.h"

/**
 * _strlen - Count lenght of the poniter
 * @s: pointer
 * Return: lenght
*/
int _strlen(char *s)
{
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}


/**
* _strchr - a function that locates a character in a string
* @s: pointer that locate a character.
* Return: pointer.
*/
int _strchr(char *s)
{
	if (s[0] == 47)
		return (0);
	else
		return (-1);
}


/**
* _strcat - appends the src string to the dest string.
* @dest: pointer to appens src.
* @src: appends to dest.
* Return: pointer.
*/
char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest);
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}


/**
* *_strcpy - function that copies the string pointed to by src,
* including the terminating null byte (\0), to the buffer pointed to by dest.
* @dest: pointer to paste
* @src: pointer to copy
* Return: pointer.
*/
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}

	dest[x] = '\0';
	return (dest);
}

/**
* _strcmp - function that compares two strings.
* @s1: string nro 1.
* @s2: string nro 2.
* Return: comparate.
*/
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}
