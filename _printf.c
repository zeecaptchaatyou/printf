#include "main.h"

/**
 * _printf - creating a printf function.
 * @format: identifier to look for.
 *
 * Return: the length of the string.
 */

int _printf(const char *format, ...)
{
	int printedChars = 0;
	va_list args_list;

	if (format == NULL)
		return (-1);
	va_start(args_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printedChars++; }
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				write(1, format, 1);
				printedChars++; }
			else if (*format == 'c')
			{
				char ct = va_arg(args_list, int);

				write(1, &ct, 1);
				printedChars++; }
			else if (*format == 's')
			{
				char *string = va_arg(args_list, char*);
				int lenString = 0;

				while (string[lenString] != '\0')
					lenString++;
				write(1, string, lenString);
				printedChars += lenString; } }

		format++; }
	va_end(args_list);
	return (printedChars); }
