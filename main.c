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
	

	if ((r_getline = getline(&line, &len, stdin)) == -1)
	{
                free(line);
                exit(0);
        }

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
 *@argc: arguments count
 *@argv: arguments vectors
 * Return: int
 */
int main(void)
{
	size_t len = 0, j;
	char *line = NULL, **parsed_input;
	ssize_t r_getline = 0;

	/*signal(SIGINT, ctrl_c);*/
	if (!isatty(STDIN_FILENO))
	{
		non_interactive();
	}
	while (1)
	{
		_printf("$ ");
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
