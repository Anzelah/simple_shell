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
 * _printf - prints a string
 *@str: the string to print
 */

void _printf(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
/**
 * _strcmp - compares two string
 *@s1: first string
 *@s2: second string
 * Return: 1 if equal 0 if not
 */

