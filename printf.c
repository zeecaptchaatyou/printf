#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	int num_char_print = 0;
	va_list args_list;

	if (format == NULL)
	{
		return (-1); }
	va_start(args_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			num_char_print++; }
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args_list, int);

				write(1, &c, 1);
				num_char_print++; }
			else if (*format == 's')
			{
				char *str = va_arg(args_list, char*);
				int length_of_string = 0;

				while (str[length_of_string] != '\0')
					length_of_string++;
				write(1, str, length_of_string);
				num_char_print += length_of_string; }
			else if (*format == '%')
			{
				write(1, format, 1);
				num_char_print++; }
			else if (*format == '\0')
			{
				break; }
		format++; }
	va_end(args_list);
	return (num_char_print); }
}
