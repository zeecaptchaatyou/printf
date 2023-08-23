#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string
 * Return: number of bytes written to standard output
*/
int _printf(const char *format, ...)
{ size_t i, len, (*spec_ptr)(ssize_t, size_t), (*uspec_ptr)(size_t, size_t);
size_t (*strspec_ptr)(char *, size_t);
char c, *err_msg = "(null)";
va_list ments;
va_start(ments, format);
if (format == NULL)
{write(1, err_msg, _strlen(err_msg));
return (0); }
for (i = 0, len = 0; format[i]; i++)
{c = format[i];

if (c == '%')
{
++i, c = format[i];
if (c == 'd' || c == 'i')
{spec_ptr = i_spotify(c);
if (spec_ptr != NULL)
len = spec_ptr(va_arg(ments, int), len); }
else if (sort(c) == 1)
{uspec_ptr = ui_spotify(c);
if (uspec_ptr != NULL)
len = uspec_ptr(va_arg(ments, unsigned int), len); }
else if (sort(c) == 2)
{strspec_ptr = str_spotify(c);
if (strspec_ptr != NULL)
len = strspec_ptr(va_arg(ments, char *), len); }
else if (sort(c) == 3)
len = print_char(va_arg(ments, int), len);
else if (c == '%')
write(1, &c, 1), len += 1;
else
write(1, &c, 1); }
else
write(1, &c, 1), len += 2; }
va_end(ments);
return (len % 2 ?  (len + 1) / 2 : len / 2); }
