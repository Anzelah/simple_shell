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
 * _strncpy - copy n string from src to dest
 *@dest: destination string
 *@src: source string
 *@n: number of bytes to copy
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';
	return (dest);
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
		if (_strncmp(nm, environ[i], strlen(nm)) == 0)
		{
			r = _strstr(environ[i], "=");
			r++;
			return (r);
		}
	}
	return (NULL);
}
