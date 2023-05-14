#include "main.h"
/**
 * _strlen - get the length of a string
 *@str: the string
 * Return - int
 */
unsigned long int _strlen( char *str)
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
	write( STDOUT_FILENO, str, _strlen(str));
}
/**
 * main - entry point
 *@argc: arguments count
 *@argv: arguments vectors
 * Return - int 
 */

int main(int argc, char **argv)
{
	size_t len = 0;
	char *line = NULL;
	ssize_t r_getline;
	while (1)
	{
		r_getline = getline(&line, &len, stdin);
		_printf("input = \n");
		break;
	}
	return (0);
}
