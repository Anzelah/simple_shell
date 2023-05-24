#include "main.h"

/**
 * non_interactive - to execute non-interactive mode
 *
 */
void non_interactive(void)
{
	size_t len = 0, j;
	char *line = NULL, **parsed_input;
	ssize_t r_getline = 0;

	while ((r_getline = getline(&line, &len, stdin)) != -1)
	{
		if (check_blanks(line) || _strlen(line) == 0)
		{
			free(line);
			continue;
		}
		for (j = _strlen(line) - 1; j > 0; j--)/* check for empty space */
		{
			if (line[j] != ' ' && line[j] != '\n' && line[j] != '\t')
				break;
			line[j] = '\0';
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
}

/**
 * main - entry point
 * Return: int
 */
int main(void)
{
	size_t len = 0, j;
	char *line = NULL, **parsed_input;
	ssize_t r_getline = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		else
		{
			non_interactive();
		}
		r_getline = getline(&line, &len, stdin);
		if (r_getline == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		if (check_blanks(line) || _strlen(line) == 0)
		{
			free(line);
			continue;
		}
		for (j = _strlen(line) - 1; j > 0; j--)/* check for empty space */
		{
			if (line[j] != ' ' && line[j] != '\n' && line[j] != '\t')
				break;
		line[j] = '\0';
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
