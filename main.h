#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct s_action - action's structure
 *@cmd_name: command's name
 *@flags: flags used with the command (-)
 *@args: arguments of the command
 */
struct s_action
{
char *cmd_name;
char **flags;
char **args;
};
typedef struct s_action _action;
/*String manipulation*/
unsigned long int _strlen( char *str);
void _printf(char *str);

/*Helper functions*/
char **parse_input(char *);
_action interpret_input(char**);
int execute_action(_action);
#endif
