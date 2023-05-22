#include "main.h"
/**
 * getlineArgv - get line from argument
 *@argc: argc
 *@argv: argv
 * Return: char*
*/
char *getlineArgv(int argc, char **argv)
{
	char *line = NULL;
	int i, j, k;

	line = malloc(1024 * sizeof(char) + 1);
	i = 0;
	for (j = 1; j < argc; j++)
	{
		for (k = 0; argv[j][k] != '\0'; k++, i++)
			line[i] = argv[j][k];
	}
	return (line);
}
