#include "main.h"

/**
 * print_percent - literally prints percent
 * @args: variable list
 * @flags: flags specifier
 * Return: 1
*/
int print_percent(va_list args, int flags)
{
char *str = va_arg(args, char *);
int len = _strlen(str);
/*remember, this is just some dummy code*/
if (flags == 0)
flags += len;
flags = 1;
write(1, "%", 1);
return ((flags + 1) - 1);
}


/**
 * print_reverse - prints a string in revers
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */
int print_reverse(va_list args, int flags)
{
int i;
char *str = va_arg(args, char *);
flags = 0;
while (str[flags])
flags++;

for (i = flags - 1; i >= 0; i--)
write(1, &str[i], 1);

return (flags);
}

/**
 * print_rot13 - prints a string using rot13 encoding
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */

int print_rot13(va_list args, int flags)
{
char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
int len = 0, i = 0, j = 0;
char *s, *str =  va_arg(args, char *);

if (flags == 0)
len += 1;
if (str == NULL)
{
write(1, "(null)", 6);
return (6);
}

len = _strlen(str);
s = (char *)malloc(len *sizeof(char));
if (s == NULL)
return (0);

_strcpy(s, str);
for (i = 0; s[i]; i++)
{
for (j = 0; input[j]; j++)
{
if (s[i] == input[j])
{
s[i] = output[j];
break; }}}


write(1, s, i);
free(s);
return (len);
}
