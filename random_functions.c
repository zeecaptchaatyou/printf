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
 * _isalpha - returns 1 if c is an alphabet else 0 if it's a betabet
 * (I can't with my dry jokess 😩)
 * @c: character to be checked
 * Return: 1 if c is an alphabet else 0
*/
int _isalpha(char c)
{
return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _isupper - checks if c is an uppercase alphabet
 * @c: character to be checked
 * Return: 1 if c is an uppercase alphabet, 0 otherwise
*/
int _isupper(char c)
{
return (c >= 'A' && c <= 'Z');
}

/**
 * _islower - checks if c is a lowercase alphabet
 * @c: character to be checked
 * Return: 1 if c is lower else 0
*/
int _islower(char c)
{
return (c >= 'a' && c <= 'z');
}
