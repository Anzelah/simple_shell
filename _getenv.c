#include "main.h"

/**
 * _strstr - search for substring
 *@haystack: string
 *@needle: substring
 * Return: pointer to the first occurence of needle
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j, k;

	if (needle[0] == '\0')
		return (haystack);
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			k = 0;
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
				{
					k = 1;
					break;
				}
			}
			if (k == 0)
				return (haystack + i);
		}
	}
	return (NULL);
}
/**
 * _strncmp - compares two strings
 *@s1: first string
 *@s2: second string
 *@n: length
 * Return: 0 if equal, an other integer if not
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (1)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
		if (i >= n)
		return (0);
	}
}
/**
 * _getenv - similar as getenv
 * @nm: name to search
 * Return: char*
 */
char *_getenv(char *nm)
{
	int i;
	char *r;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(nm, environ[i], _strlen(nm)) == 0)
		{
			r = _strstr(environ[i], "=");
			r++;
			return (r);
		}
	}
	return (NULL);
}
