#include "main.h"

/**
 * _strlen - get the length of a string
 *@str: the string
 * Return: int
 */

unsigned long int _strlen(char *str)
{
	unsigned long int n = 0;

	while (str[n])
		n++;
	return (n);
}

/**
 * _printe - prints an error
 *@str: the string to print
 */

void _printe(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
}


/**
 * _printf - prints a string
 *@str: the string to print
 */

void _printf(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * _strdup - duplicates  string
 *@src: string
 * Return: pointer to the new string
 */

char *_strdup(char *src) 
{
	char *new_string;
	int i = 0;

	new_string = malloc(sizeof(char) * _strlen(src) + 1);
	if (!new_string)
		return (NULL);

	while (*src)
	{
		new_string[i++] = *src++;
	}
	new_string[i] = '\0';

	return (new_string);
}
	
/*char *_strdup(char *src)
{
	return (strdup(src));
} */

