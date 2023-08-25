#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to be counted
 * Return: length of s.
*/
int _strlen(char *s)
{
size_t i = 0;
while (s[i])
i++;
return (i);
}

/**
 * _strcpy - copies a string from source to buffer provided by dest
 * @dest: buffer to be written in
 * @src: buffer to be written from
 * Return: pointer to dest
*/
char *_strcpy(char *dest, const char *src)
{
char *ptr = dest;
while (*src != '\0')
{
*ptr = *src;
src++, ptr++;
}
*ptr = '\0';
return (dest);
}
