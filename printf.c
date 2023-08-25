#include "main.h"

/**
 * _printf - custom printf
 * @format: variadic argument
 * Return: number of characters printed to stdout
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0, i, j, flags = 0, start, end;
conversion_t conversion[] = {
{'c', print_char},
{'s', print_string},
{'%', print_percent},
{'d', print_int},
{'i', print_int},
{'b', print_binary},
{'u', print_uint},
{'o', print_octal},
{'x', print_hex},
{'X', print_HEX},
{'S', print_S},
{'p', print_pointer},
{'R', print_rot13},
{'r', print_reverse},
{'\0', NULL}};
va_start(args, format);
for (i = 0; format && format[i]; i++)
{
if (format[i] == '%')
{start = i + 1, end = start;
while (format[end] && is_flag(format[end]))
end++;

flags = handle_flags(format, start, end);

for (j = 0; conversion[j].format != '\0'; j++)
{
if (conversion[j].format == format[i + 1])
{count += conversion[j].func(args, flags), i++;
break; }}}
else
{write(1, &format[i], 1), count++; }}

va_end(args);
return (count); }
