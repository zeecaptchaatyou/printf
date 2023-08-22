#include "main.h"

/**
 * print_integer - Prints an integer to the standard output
 * @n: integer to be printed
 *
 * Return: number of characters printed
 */

int print_integer(int n)
{
char buf[20];
int len = 0, neg = n < 0;
n = neg ? -n : n;
while (n)
	buf[len++] = n % 10 + '0';
	n /= 10;
if (!len)
	buf[len++] = '0';
if (neg)
	buf[len++] = '-';
while (len--)
	write(1, buf + len, 1);
return (len);
}
/**
 * printfInteger - customer printf function to print integers
 * @format: The format specifier
 *
 * Return: number of characters printed.
 */
int printfInteger(const char *format, ...)
{
va_list args;
int printedChars = 0;
va_start(args, format);
if (!format)
	return (-1);
while (*format)
{
if (*format != '%')
{
	write(1, format, 1);
	printedChars++;
else if (*++format == 'd' || *format == 'i')
printedChars += print_integer(va_arg(args, int));
else if (!*format)
	break;
else
	write(1, "%", 1);
printedChars++;
format++;
}
va_end(args);
return (printedChars);
}

