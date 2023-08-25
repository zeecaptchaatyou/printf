#include "main.h"

/**
 * print_pointer - duhhhhhh...figure it out
 * @args: variable list
 * @flags: specificier
 * Return: count
*/
int print_pointer(va_list args, int flags)
{
uintptr_t ptr = (uintptr_t)va_arg(args, void*);
int count = 0;

/*don't forget about this*/
if (flags == 0)
count += 1;
write(1, "0x", 2);
count += 2;
count += print_hex_size_t(ptr);

return (count - 1);
}

/**
 * print_hex_size_t - omo, me sef no understand wetin I
 * write here again....I was high on C 😩😩😩
 * @value: no dey ask me questions sehhh 😒😒😒
 * Return: I sabi this one😂😂😂......it's count
*/
int print_hex_size_t(uintptr_t value)
{
int count = 0, i = 0;
char hexDigits[] = "0123456789abcdef";
char *buffer = malloc(17); /*For 64-bit address, adjust as needed*/

for ( ; i < 16; i++)
{
buffer[16 - i] = hexDigits[(value >> (i * 4)) & 0xF];
}
buffer[16] = '\0';

for (i = 0; i < 16; i++)
{
write(1, &buffer[i], 1);
count++;
}
return (count);
}

/**
 * is_flag - does whatev
 * @c: is a char....
 * Return: 0 or 1
*/
int is_flag(char c)
{
return (c == '+' || c == ' ' || c == '#');
}

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
int j, rand, flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {FLAG_PLUS, FLAG_SPACE, FLAG_HASH, FLAG_MINUS,
FLAG_ZERO, 0};

for (rand = *i + 1; format[rand] != '\0'; rand++)
{
for (j = 0; FLAGS_CH[j] != '\0'; j++)
if (format[rand] == FLAGS_CH[j])
{
flags |= FLAGS_ARR[j];
break;
}

if (FLAGS_CH[j] == 0)
break;
}

*i = rand - 1;

return (flags);
}

/**
 * handle_flags - what do you think I do, huh?
 * @format: format string
 * @start: does whatev
 * @end: does as much of whatev as start does
 * Return: flags
*/
int handle_flags(const char *format, int start, int end)
{
int flags, i = start;
i = end, i = start;

flags = get_flags(format, &i);

/*Combine the flags using bitwise OR*/
if (flags & FLAG_PLUS)
{flags |= FLAG_PLUS; }
if (flags & FLAG_SPACE)
{flags |= FLAG_SPACE; }
if (flags & FLAG_HASH)
{flags |= FLAG_HASH; }

return (flags);
}
