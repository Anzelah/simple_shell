#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
/**
 * struct s_string - string structure (a way to append multipe strings)
 *@value: string value
 *@next: next element
 */
typedef struct s_string
{
    char *value;
    unsigned long int len;
    struct s_string *next;
} StringList;
/**
 * struct s_action - action's structure
 *@cmd_name: command's name
 *@flags: flags used with the command (-)
 *@args: arguments of the command
 */
struct s_action
{
char *cmd_name;
char **args;
};
typedef struct s_action _action;
/*String manipulation*/
unsigned long int _strlen( char *str);
void _printf(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/*linked list manipulation */
StringList *AppendString(StringList **head, const char *str);

/*Helper functions*/
char **parse_input(char *);
_action *interpret_input(char**);
int execute_action(_action);

/* parsing */
void free_tokens(char **tokens);

/*free functions*/
void free_action(_action *action);
#endif
