#include "main.h"


/**
 * print_h_decimal - prints the hexadecimal value of n to stdout
 * @n: number to be printed
 * @count: the argument count += number of chars printed to stdout
 * Return: count
*/
size_t print_h_decimal(size_t n, size_t count)
{
int i = 0;
char *str, c;

str = _u_itoa(n, 16);
if (str == NULL)
{
free(str);
return (0);
}
while (str[i])
{
c = str[i];
write(1, &c, 1), i++, count++;
}
free(str);
return (count);
}

/**
 * print_uppercase_h_decimal - prints the uppercase hexadecimal value of n
 * @n: number to be printed
 * @count: the argument count += number of chars printed to stdout
 * Return: count
*/
size_t print_uppercase_h_decimal(size_t n, size_t count)
{
int i = 0;
char *str, c;

str = _u_itoa(n, 16);
if (str == NULL)
{
free(str);
return (0);
}
while (str[i])
{
if (str[i] > 96 && str[i] < 123)
str[i] -= 32;
c = str[i];
write(1, &c, 1), i++, count++;
}
free(str);
return (count);
}

/**
 * print_u_int - prints unsigned value of of n to stdout
 * @n: number to be printed
 * @count: count += _strlen(str)
 * Return: count
*/
size_t print_u_int(size_t n, size_t count)
{
int i = 0;
char *str, c;
str = _u_itoa(n, 10);
if (str == NULL)
{
free(str);
return (0);
}
while (str[i])
{
c = str[i], write(1, &c, 1);
i++, count++;
}
free(str);
return (count);
}
