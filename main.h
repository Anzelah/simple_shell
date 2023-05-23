#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include<sys/wait.h>
#include <sys/stat.h>
extern char **environ;

/**
 * struct s_string - string structure (a way to append multipe strings)
 *@value: string value
 *@len: string length;
 *@next: next element
 */
typedef struct s_string
{
	char *value;
	unsigned long int len;
	struct s_string *next;
} StringList;

/*String manipulation*/
unsigned long int _strlen(char *str);
void _printf(char *str);
void _printe(char *);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *, char *);
char *getlineArgv(int argc, char **argv);

/*linked list manipulation */
StringList *AppendString(StringList **head, char *str); /* remove const */

/*Helper functions*/
char **parse_input(char *);
int execute_action(char **);

/* handle path */
char *find_path(char *);
int is_exec(char *);
char *_getenv(char *nm);

/* parsing */
void free_tokens(char **tokens);

#endif
