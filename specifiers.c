#include "main.h"

/**
 * print_binary - converts to binary, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: format specifier
 * Return: numer of characters writtent to stdout
*/
int print_binary(va_list args, int flags)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0, index = 0, i;
char *buffer = malloc(32); /*Maximum 32-bit binary representation*/

if (buffer == NULL)
return (0);

if (flags & FLAG_HASH)
write(1, "0b", 2);

if (num == 0)
{
write(1, "0", 1);
return (1);
}

while (num > 0)
{
buffer[index++] = num % 2 + '0';
num /= 2;
}

for (i = index - 1; i >= 0; i--)
{
write(1, &buffer[i], 1);
count++;
}

return (count);
}

/**
 * print_hex_char - won't even bother to explain
 * @c: extreeeeeeemely useful here hun.
 * Return: 2.
*/
int print_hex_char(char c)
{
char hexDigits[] = "0123456789ABCDEF";
char buffer[3];
buffer[0] = hexDigits[(c >> 4) & 0x0F];
buffer[1] = hexDigits[c & 0x0F];
buffer[2] = '\0';

write(1, buffer, 2);
return (2);
}

/**
 * print_S - Almighty Mr Barbier wanted this so, here it is
 * @args: variable list
 * @flags: flag specifier
 * Return: numer of characters writtent to stdout
*/
int print_S(va_list args, int flags)
{
char *str = va_arg(args, char*);
int count = 0, i;

if (str == NULL)
{
write(1, "(null)", 6);
return (6);
}
/*
 * thisis just some way to trick the compiler into not noticing
 *flags is unused, remember this
 */
if (flags == 0)
count += 1;
for (i = 0; str[i]; i++)
{
if (str[i] >= 32 && str[i] < 127)
{
write(1, &str[i], 1);
count++;
}
else
{
write(1, "\\x", 2);
count += 2;
count += print_hex_char(str[i]);
}
}

return (count - 1);/*remove the one added previously*/
}

/**
 * print_char - rides a c(H)arrrrrr
 * @args: variable list
 * @flags: flag specifier
 * Return: 1
*/
int print_char(va_list args, int flags)
{
char c = (char)va_arg(args, int);
write(1, &c, 1);
if (flags == 0)
return ((1 + 1) - 1);
else
return (1);
}

/**
 * print_string - what do think it does? huh?
 * @args: variable list
 * @flags: flag specifier
 * Return: numer of characters writtent to stdout
*/
int print_string(va_list args, int flags)
{
int len = 0, j;
char *str = va_arg(args, char*);
if (str == NULL)
{
write(1, "(null)", 6);
return (6);
}
if (flags == 0)
j = len;
/*
 *the whole existence of j is to trick the compiler into believing
 *flags isn't an unused variable. I haven't figured out a way to implement
 *the flags and precision yet....I'll come back to this code later
 *, I promise
 */
while (str[len])
len++;
write(1, str, len);
len += j;
return (len - j);
}
