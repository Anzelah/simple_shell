#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * Return: array
 */

char **parse_input(char *str)
{
	char *parsed;
	char **tokens; /* this is an array */
	char *src; /* hold our string on heap*/
	char *delim = " \n";
	int length = 0;
      	int count_tokens = 0;

	src = malloc(sizeof(char) * strlen(str));
	if (src == NULL)
		return (NULL);

	strcpy(src, str);

	parsed = strtok(str, delim);
	while (parsed != NULL)
	{
		count_tokens++;
		parsed = strtok(NULL, delim);
	}
	count_tokens++;

	tokens = malloc(sizeof(char *) * count_tokens);
	if (tokens == NULL)
		return (NULL);

	parsed = strtok(src, delim);
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
