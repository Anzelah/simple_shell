#include "main.h"

/**
 * main - entry point
 *@argc: arguments count
 *@argv: arguments vectors
 * Return: int
 */
int main(int argc, char **argv)
{
	size_t len = 0;
	char *line = NULL;
	ssize_t r_getline = 0;
	char **parsed_input;
	int j;

	while (1)
	{
		if (argc == 1)
		{	
			_printf("#cisfun$ ");
			line = NULL;
			r_getline = getline(&line, &len, stdin);
			for (j = 0; line[j] != '\0' && line[j] != '\n'; j++);
			line[j] = '\0';
		}
		else
			line = getlineArgv(argc, argv);
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
		/*action = interpret_input(parsed_input);*/
		if (!execute_action(parsed_input))
			break;
		free_tokens(parsed_input);
	}
	return (0);
}
