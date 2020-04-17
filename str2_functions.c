#include "shell.h"

/**
* *_atoi - print only number
* @s: pointer to extrac number
* Return: pointer.
*/
int _atoi(char *s)
{
	int aux, i, sig;

	sig = 1;
	i = aux = 0;
	while ((s[i] < '0' || s[i] > '9') && s[i] != 0)
	{
		if (s[i] == '-')
			sig = sig * -1;
		i++;
	}
	while ((s[i] >= '0' && s[i] <= '9') && s[i] != 0)
	{
		if (aux >= 0)
		{
			aux = aux * 10 - (s[i] - '0');
			i++;
		}
		else
		{
			aux = aux * 10 - (s[i] - '0');
			i++;
		}
	}
	sig = sig * -1;
	return (aux * sig);
}

/**
 * rev_string - isdigit
 * @s: integer
 * Return: prints alphabet
*/
void rev_string(char *s)
{
	int i = 0;
	int len = 0;
	char save = 0;
	int final = 0;

	for (i = 0; s[i] != '\0'; i++)
		len++;
	final = len - 1;

	for (i = final; i >= (final - i); i--)
	{
		save = s[(final - i)];
		s[(final - i)] = s[i];
		s[i] = save;
	}
}

/**
* _itos - change int to string
 * @num: number to conver
 * @str: pointer
 * @cont: counter
 * @sign: signal
 * Return: None
*/
void _itos(long int num, char *str, int cont, int sign)
{
	if (num == 0)
	{
		if (sign == -1)
		{
			str[0] = '-';
			str[1] = '\0';
		}
		else
			str[0] = '\0';
		rev_string(str - cont);
	}
	else
	{
		str[0] = (num % 10) + '0';
		num /= 10;
		_itos(num, str + 1, cont + 1, sign);
	}
}

/**
* find_slash - detects an slash or an space on the shell
* @c: the slash or space
* @str: the string that the user enter
* Return: an int
*/
int find_slash(char c, char *str)
{
	int i = 0;

	while (str[i])
	{
	if (str[i] != c && str[i] != ' ')
		return (0);
	i++;
	}
	return (1);
}

/**
* quotes_echo - a function that locates a quote on the string
* @s: pointer that locate a character.
* @c: quotes.
* Return: pointer.
*/
char *quotes_echo(char *s, char c)
{
	if (*s == c)
		s = strtok(s, "\"");
	return (s);
}
