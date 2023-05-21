#include "main.h"
/**
 * getlineFromFile - get line from file descriptor
 *@line: where to store line buffer
 *@len: line lenght
 *@file_descriptor: the file
 * Return: int
*/
int getline(char **line, int *len, int file_descriptor)
{
	char c[1];
	char buff[1024];
	int n, i;
	buff[0] = '\0';
	i = 0;
	while (n = read(file_descriptor, c, 1) > 0)
	{

		if (c[0] == '\n')
		{
			buff[i] = '\0';
			break;
		}
		buff[i++] = c[0];
	}
	*len = i + 1;
	*line = strdup(buff);
	return n;
}
/*
int main(int argc, char **argv)
{
	int f = open("file.txt", O_RDONLY);
	char *b;
	int nn, l;
	do
	{

		nn = getlineFromFile(&b, &l, f);
		printf("#%s#", b);
		free(b);
	} while (nn > 0);
	close(f);
	return (0);
}*/
