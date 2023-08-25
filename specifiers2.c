#include "main.h"

/**
 * print_int - converts argument number to int, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */
int print_int(va_list args, int flags)
{
int num = va_arg(args, int), count = 0, temp, len, i;
char *buffer;

/*
 * still contemplating on adding an extra if block to handle
 * the conditon whereby ' ' and '+' are present.....not in
 * the mood yet :smile
*/
if ((flags & FLAG_PLUS) == true)
write(1, "+", 1), count++;
if (flags & FLAG_SPACE)
write(1, " ", 1), count++;

if (flags & FLAG_PLUS)
write(1, "What", 4);

if (num < 0)
{write(1, "-", 1), count++;
count++;
num = -num; }

temp = num, len = 0;

while (temp > 0)
{temp /= 10, len++; }

buffer = (char *)malloc(len);
if (buffer == NULL)
return (0);

for (i = len - 1; i >= 0; i--)
{buffer[i] = num % 10 + '0';
num /= 10; }

write(1, buffer, len);
count += len;

free(buffer);
return (count);
}

/**
 * print_uint - converts argument number to uint, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return:  number of characters written to stdout
*/
int print_uint(va_list args, int flags)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0, index = 0, i;
char *buffer = malloc(32); /*Maximum 32-bit decimal representation*/

if (buffer == NULL)
return (0);

if (num == 0)
{
write(1, "0", 1);
return (1);
}

while (num > 0)
{
buffer[index++] = num % 10 + '0';
num /= 10;
}
if (flags == 0)
i = 1;

for (i = index - 1; i >= 0; i--)
{
write(1, &buffer[i], 1);
count++;
}

free(buffer);
return (count);
}


/**
 * print_octal - converts argument number to octal, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */
int print_octal(va_list args, int flags)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0, index = 0, i;
char *buffer = malloc(32); /*Maximum 32-bit octal representation*/
if (buffer == NULL)
return (0);

if (flags & FLAG_HASH)
write(1, "0", 1);

if (num == 0)
{
write(1, "0", 1);
return (1);
}

while (num > 0)
{
buffer[index++] = num % 8 + '0';
num /= 8;
}

for (i = index - 1; i >= 0; i--)
{
write(1, &buffer[i], 1);
count++;
}

free(buffer);
return (count);
}

/**
 * print_hex - converts argument number to hex, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */
int print_hex(va_list args, int flags)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0, index = 0, i = 0;
char hexDigits[] = "0123456789abcdef";
char *buffer = malloc(32); /*Maximum 32-bit hexadecimal representation*/

if (buffer == NULL)
return (0);

if (flags & FLAG_HASH)
write(1, "0x", 2);

if (num == 0)
{
write(1, "0", 1);
return (1);
}

while (num > 0)
{
buffer[index++] = hexDigits[num % 16];
num /= 16;
}

for (i = index - 1; i >= 0; i--)
{
write(1, &buffer[i], 1);
count++;
}

free(buffer);
return (count);
}

/**
 * print_HEX - converts argument number to HEX, formats specifically
 * and prints to stdout
 * @args: variable list
 * @flags: flag specifier
 * Return: number of characters written to stdout
 */
int print_HEX(va_list args, int flags)
{
unsigned int num = va_arg(args, unsigned int);
int count = 0, index = 0, i;
char hexDigits[] = "0123456789ABCDEF";
char *buffer = malloc(32); /*Maximum 32-bit hexadecimal representation*/

if (buffer == NULL)
return (0);

if (flags & FLAG_HASH)
write(1, "0X", 2);

if (num == 0)
{
write(1, "0", 1);
return (1);
}

while (num > 0)
{
buffer[index++] = hexDigits[num % 16];
num /= 16;
}

for (i = index - 1; i >= 0; i--)
{
write(1, &buffer[i], 1);
count++;
}

free(buffer);
return (count);
}
