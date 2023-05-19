#include "main.h"

/**
 * free_tokens - free memory allocated to individual arrays
 * @tokens: arrays to be freed
 */

void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/**
 * parsed_input - tokenize the string into multiple pieces
 * @line: input string to be tokenized
 *
 * Return: always 0
 */

char **parsed_input(char *line)
{
	char *parsed;
	char **tokens; /* this is an array */
	char *str; /* hold our string on heap*/
	char *delim = " \n";
	int length = 0, count_tokens = 0;

	str = malloc(sizeof(char) * (strlen(line) + 1));
	if (str == NULL)
		return (NULL);

	strcpy(str, line);

	parsed = strtok(line, delim);
	while (parsed != NULL)
	{
		count_tokens++;
		parsed = strtok(NULL, delim);
	}
	count_tokens++;

	tokens = malloc(sizeof(char *) * count_tokens);
	if (tokens == NULL)
		return (NULL);

	parsed = strtok(str, delim);
	while (parsed != NULL)
	{
		tokens[length] = malloc(sizeof(char) * (strlen(parsed) + 1));
		strcpy(tokens[length], parsed);
		length;
		parsed = strtok(NULL, delim);
	}
	tokens[length] = NULL;

	free_tokens(tokens); /* created individual function to free all the arrays */
	free(str);

	return (0);
}
