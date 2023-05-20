#include "main.h"

/**
 * interpret_input - interpert the input ([ls,-l,/home] -> action
 *@parsed_input: parsed input
 * Return: action
 */
_action *interpret_input(char **parsed_input)
{
	_action *action = NULL;
	long int nb_tokens = 0;
	unsigned int i, nb_args = 0;

	while (parsed_input[nb_tokens] != NULL)
		nb_tokens++;
	action = malloc(sizeof(_action));
	if (!action)
		return (NULL);

	action->cmd_name = _strdup(parsed_input[0]); /*getting the command name*/
	for (i = 1; i < nb_tokens; i++)				 /*getting flags and arguments*/
	{
		nb_args++;
	}
	nb_args++; /*to add NULL at the end*/
	action->args = malloc(sizeof(char *) * nb_args);
	if (action->args == NULL)
		return (NULL);
	for (i = 1; i < nb_tokens; i++)
	{
		action->args[i - 1] = _strdup(parsed_input[i]);
	}
	action->args[i - 1] = NULL;
	return (action);
}
/**
 * free_array - free arrays
 * @data: the arrat to be freed
 */
void free_array(char **data)
{
	int i = 0;

	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
}
/**
 * free_action - free action
 *@action: the action to be freed
 */
void free_action(_action *action)
{
	free(action->cmd_name);
	free_array(action->args);
	free(action);
}

