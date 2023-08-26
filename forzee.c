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

/**
 * is_spec - checks if the currect character is a specifier
 * @c: a character in the format string
 * Return: 0 or non-zero value
*/
int is_spec(char c)
{
return (c == 'b' || c == 'c' || c == 'd' || c == 'i'
|| c == 'o' || c == 'p' || c == 'r' || c == 'R' || c == 's'
|| c == 'S' || c == 'u' || c == 'x' || c == 'X');
}
