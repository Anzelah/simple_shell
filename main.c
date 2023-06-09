#include "main.h"

/**
 * removeComment - remove comment
 * @linem: line
 */
void removeComment(char **linem)
{
	size_t j;
	char *line = *linem;

	for (j = 0; j < _strlen(line); j++)
		if (line[j] == '#')
		{
			line[j] = '\0';
			break;
		}
}
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
		if (check_blanks(line) == _strlen(line) || _strlen(line) == 0)
		{
			free(line);
			continue;
		}
		for (j = _strlen(line) - 1; j > 0; j--) /* check for empty space */
		{
			if (line[j] != ' ' && line[j] != '\n' && line[j] != '\t')
				break;

			line[j] = '\0';
		}
		removeComment(&line);
		parsed_input = parse_input(line);
		free(line);
		if (!execute_action(parsed_input, parsed_input))
		{
			free_tokens(parsed_input);
			break;
		}
		line = NULL;
		free_tokens(parsed_input);
	}
	free(line);
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

	signal(SIGINT, ctrl_c);
	while (1)
	{
		line = NULL;
		if (isatty(STDIN_FILENO))
			_printf("$ ");
		else
			non_interactive();
		r_getline = getline(&line, &len, stdin);
		if (r_getline == -1)
		{
			free(line);
			exit(0);
		}
		if (check_blanks(line) == _strlen(line) - 1 || _strlen(line) == 0)
		{
			free(line);
			continue;
		}
		for (j = _strlen(line) - 1; j > 0; j--) /* check for empty space */
		{
			if (line[j] != ' ' && line[j] != '\n' && line[j] != '\t')
				break;

			line[j] = '\0';
		}
		removeComment(&line), parsed_input = parse_input(line);
		free(line);
		if (!execute_action(parsed_input, parsed_input))
		{
			free_tokens(parsed_input);
			break;
		}
		free_tokens(parsed_input);
	}
	return (0);
}
