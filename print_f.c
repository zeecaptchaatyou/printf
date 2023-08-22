#include "main.h"

void print_to_buffer(char buffer[], int *buff_index);

/**
 * _printf - Custom printf function
 * @format: Format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFFER_SIZE)
				print_to_buffer(buffer, &buff_index);
			printed_chars++;
		}
		else
		{
			print_to_buffer(buffer, &buff_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print_format(format, &i, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_to_buffer(buffer, &buff_index);

	va_end(args);

	return (printed_chars);
}

/**
* print_to_buffer - Prints the contents of the buffer if it exists
* @buffer: Array of characters.
* @buff_index: Index at which to add the next character, represents the length.
*/
void print_to_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}

