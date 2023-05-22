#include "main.h"
/**
 * getlinefromfile - get line from file descriptor
 *@line: where to store line buffer
 *@len: line lenght
 *@file_descriptor: the file
 * Return: int
*/
int getlinefromfile(char **line, size_t *len, int file_descriptor)
{
	char c[1];
	char buff[1024];
	int n, i;

	buff[0] = '\0';
	i = 0;

	while ((n = read(file_descriptor, c, 1)) > 0)
	{

		if (c[0] == '\n')
		{
			buff[i] = '\0';
			break;
		}
		buff[i++] = c[0];
	}
	*len = i + 1;
	*line = _strdup(buff);
	return (n);
}
