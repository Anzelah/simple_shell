#include "main.h"

/**
 * main - entry point
 *@argc: arguments count
 *@argv: arguments vectors
 * Return: int
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	size_t len = 0, j;
	char *line = NULL, **parsed_input;
	ssize_t r_getline = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf("#cisfun$ ");
		line = NULL;
		r_getline = getline(&line, &len, stdin);
		for (j = 0; line[j] != '\0' && line[j] != '\n'; j++)
		{ /* for betty */
		}
		line[j] = '\0';

		if (r_getline == -1)
		{
			free(line);
			break;
		}
		if (_strlen(line) == 0)
		{
			free(line);
			continue;
		}
		parsed_input = parse_input(line);
		free(line);
		if (!execute_action(parsed_input))
		{
			free_tokens(parsed_input);
			break;
		}
		free_tokens(parsed_input);
	}
	return (0);
}
