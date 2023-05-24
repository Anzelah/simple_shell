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
 * parse_input - tokenize the string into multiple pieces
 * @str: input string to be tokenized
 *
 * Return: array
 */
char **parse_input(char *str)
{
	char *parsed;
	char **tokens; /* this is an array */
	char *src; /* hold our string on heap*/
	char *delim = " ";
	int length = 0;
	int count_tokens = 0;

	src = _strdup(str);
	if (src == NULL)
	{
		free(src);
		return (NULL);
	}
	parsed = strtok(str, delim);
	while (parsed != NULL)
	{
		count_tokens++;
		parsed = strtok(NULL, delim);
	}
	count_tokens++;

	tokens = malloc(sizeof(char *) * count_tokens);
	if (tokens == NULL)
	{
		free(src);
		return (NULL);
	}

	parsed = strtok(src, delim);
	while (parsed != NULL)
	{
		tokens[length] = _strdup(parsed);
		length++;
		parsed = strtok(NULL, delim);
	}
	tokens[length] = NULL;/* this line save my life*/
	free(src);
	return (tokens);
}
