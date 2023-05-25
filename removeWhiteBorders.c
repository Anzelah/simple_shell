#include "main.h"
/**
 * removeWhiteBorders - removes while spaces
 * @s: string
 * Return: char *
 */
char *removeWhiteBorders(char *s)
{
    long int len = _strlen(s);
    int i, j = 0, startcopying = 0;
    char *r = _strdup(s);

    if (!r)
        return (NULL);
    /*remove white space from the begining*/
    for (i = 0; i < len; i++)
    {
        if (s[i] != ' ' && s[i] != '\t')
            startcopying = 1;
        if (startcopying)
        {
            r[j] = s[i];
            j++;
        }
    }
    len = j;
    /*remove white space at the end*/
    for (i = len; i > 0; i--)
    {
        if (r[i] != ' ' && r[i] != '\t')
            break;

        r[i] = '\0';
    }
    return (r);
}
