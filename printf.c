#include "main.h"

/**
 * _printf - custom printf
 * @format: variadic argument
 * Return: number of characters printed to stdout
*/
int _printf(const char *format, ...)
{
va_list args;
int count = 0, i, flags = 0, start, end;
int (*spot_ptr)(va_list, int);

va_start(args, format);
if (format == NULL)
return (0);
for (i = 0; format && format[i]; i++)
{
if (format[i] == '%')
{
if (format[i + 1] == '\0')
continue;
start = i + 1, end = start;
while (format[end] && is_flag(format[end]))
end++;
flags = handle_flags(format, start, end);
spot_ptr = spot(format[i + 1]);
if (spot_ptr != NULL)
count += spot_ptr(args, flags), i++;
else
{write(1, &format[i], 1), count++; }}
else
write(1, &format[i], 1), count++;
}
va_end(args);
return (count); }
