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
	char *line_temp = NULL, *line = NULL, **parsed_input;
	ssize_t r_getline = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		line = NULL;
		line_temp = NULL;
		r_getline = getline(&line_temp, &len, stdin);

		for (j = 0; line_temp[j] != '\0' && line_temp[j] != '\n'; j++)
		{ /* for betty */
		}
		line_temp[j] = '\0';
		line = removeWhiteBorders(line_temp);
		free(line_temp);
		if (r_getline == -1)
		{
			free(line);
			break;
		}
		if (check_blanks(line) || _strlen(line) == 0)
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
