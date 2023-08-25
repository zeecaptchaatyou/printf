#include "main.h"

/**
 * print_rot - prints the rot 13'ed string
 * @s: string to be rot'ed, yunno
 * @count: count += _strlen(s)
 * Return: count argument incremented by length of s
*/
size_t print_rot(char *s, size_t count)
{
size_t i = 0, len = 0;
char c, *str;

if (s == NULL)
return (0);
len = _strlen(s);
str = (char *)malloc((len *sizeof(char)) + 1);
if (str == NULL)
return (0);
str = _strcpy(str, s);

for ( ; str[i] != '\0'; i++)
{
if (_isalpha(str[i]))
{
if (_islower(str[i]))
str[i] = ((str[i] - 'a' + 13) % 26) + 'a';
else if (_isupper(str[i]))
str[i] = ((str[i] - 'A' + 13) % 26) + 'A';
}
}
for (i = 0; str[i] != '\0'; i++, count++)
{
c = str[i];
write(1, &c, 1);
}
free(str);
return (count);
}

/**
* print_reverse - function that prints a string in reverse.
* @s: string to be printed
* @count: count += _strle(s)
* Return: count
*/
size_t print_reverse(char *s, size_t count)
{
char c, *str;
int len = (_strlen(s)) - 1;

if (s == NULL)
return (0);
str = (char *)malloc(((len + 1) * sizeof(char)) + 1);

if (str == NULL)
return (0);
str = _strcpy(str, s);

for ( ; len >= 0; count++, len--)
{
c = str[len];
write(1, &c, 1);
}
return (count);
}


/**
 * print_customstr - prints a string with modifications specified by meeeee
 * @s: string to be modified and printed
 * @count: count += length of the string
 * Return: count
*/
size_t print_customstr(char *s, size_t count)
{
size_t i = 0, n, j = 0;
char c, *str;
for (i = 0; s[i]; i++)
{
if ((s[i] > 0 && s[i] < 32) || s[i] >= 127 || s[i] < 0)
{
c = '\\', write(1, &c, 1), count += 1;
c = 'x', write(1, &c, 1), count += 1;
n = s[i], str = S_u_itoa(n, 16);
c = '0', write(1, &c, 1), count += 1;
for (j = 0; str[j]; j++)
c = str[j], write(1, &c, 1), count += 1;
}
else
c = s[i], write(1, &c, 1), count += 1;
}
return (count);
}


/**
 * print_address - prints a pointer to a data type
 * I tried to make this work buttt.....nah!
 * @addr: pointer to be printed
 * @count: count += number of chars printed to stdout
 * Return: count
*/
size_t print_address(void *addr, size_t count)
{
char hexDigits[] = "0123456789abcdef", c;
char buffer[19]; /*max size of a 64-bit hex nmber*/

/*aaaaaand, some typecasting's supping down there, watch out!*/
size_t value = (size_t)addr;
int i = 0;

buffer[0] = '0';
buffer[1] = 'x';

for ( ; i < 16; i++)
{
buffer[17 - i] = hexDigits[value & 0xf];
value >>= 4;
}
buffer[18] = '\n';

for (i = 0; buffer[i]; i++, count++)
{
c = buffer[i];
write(1, &c, 1);
}
return (count);
}
