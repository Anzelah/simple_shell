#include "main.h"


/**
 * add_node_end - adds new node at the end
 *@head: the head of the list
 *@str: string value
 *Return: new element
 */
StringList *AppendString(StringList **head, const char *str)
{
	unsigned int len = 0;
	StringList *new = malloc(sizeof(StringList));
	StringList *t;

	t = *head;
	if (!new)
		return (NULL);
	while (str && str[len] != '\0')
		len++;
	while (t && t->next != NULL)
		t = t->next;
	new->value = strdup(str);
	new->len = len;
	new->next = NULL;

	if (t)
		t->next = new;
	else
		(*head) = new;
	return (new);
}

