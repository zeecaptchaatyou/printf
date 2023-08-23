#include "main.h"

/**
 * print_char - prints a single character to sdout
 * @c: character to be printed
 * @count: the argument count += number of chars printed to stdout
 * Return: count
*/
size_t print_char(char c, size_t count)
{
write(1, &c, 1), count += 1;
return (count);
}

/**
 * print_string - prints a string to stdout
 * @s: string to be printed
 * @count: the argument count += number of chars printed to stdout
 * Return: count
*/
size_t print_string(char *s, size_t count)
{
size_t i = 0;
char c;
if (s == NULL)
{
return (0);
}
while (s[i])
{
c = s[i];
write(1, &c, 1), i++, count += 1;
}
return (count);
}

/**
 * print_decimal - prints decimal value of n to stdout
 * @n: number to be printed
 * @count: the argument count += number of chars printed to stdout
 * Return: count
*/
size_t print_decimal(ssize_t n, size_t count)
{
int i = 0;
char *str = _itoa(n, 10), c;
if (str == NULL)
{
free(str);
return (0);
}
for ( ; str[i]; i++, count++)
{
c = str[i];
write(1, &c, 1);
}
free(str);
return (count);
}

/**
 * print_binary - prints binary value of n to stdout
 * @n: number to be printed
 * @count: the argument count += number of chars printed to stdout
 * Return: count
*/
size_t print_binary(size_t n, size_t count)
{
int i = 0;
char *str, c;

str = _u_itoa(n, 2);
if (str == NULL)
{
free(str);
return (0);
}
for ( ; str[i]; i++, count++)
{
c = str[i];
write(1, &c, 1);
}
free(str);
return (count);
}

/**
 * print_octal - prints octal value of n to stdout
 * @n: number to be printed
 * @count: the argument count += number of chars printed to stdout
 * Return: count
*/
size_t print_octal(size_t n, size_t count)
{
int i = 0;
char *str, c;

str = _u_itoa(n, 8);
if (str == NULL)
{
free(str);
return (0);
}
for ( ; str[i]; i++, count++)
{
c = str[i];
write(1, &c, 1);
}
free(str);
return (count);
}
