#include "main.h"

/**
 * _strcat - concatenates two string
 *@s1: first string
 *@s2: second chari
 * Return: char *
 */
char *_strcat(char *s1, char *s2)
{
	unsigned int i = 0;
	unsigned int len1 = 0, len2 = 0;
	char *array;

	while (s1 && s1[len1] != '\0')
		len1++;
	while (s2 && s2[len2] != '\0')
		len2++;
	array = malloc((1 + len1 + len2) * sizeof(char));
	if (!array)
		return (NULL);
	for (i = 0; i < len1 + len2; i++)
	{
		if (i < len1)
			array[i] = s1[i];
		else
			array[i] = s2[i - len1];
	}
	array[i] = '\0';
	return (array);
}
