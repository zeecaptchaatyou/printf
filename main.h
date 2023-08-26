#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdint-gcc.h>
#include <stdlib.h>
#include <string.h>
#define FLAG_PLUS  1
#define FLAG_SPACE 2
#define FLAG_HASH  4
#define FLAG_MINUS 8
#define FLAG_ZERO 16

/**
 * struct specs - structure of the whole printf
 * @format: variadic arguement
 * @func: function pointer
*/
typedef struct specs
{
char format;
int (*func)(va_list, int flags);
} conversion_t;

extern conversion_t conversion[];

int (*spot(char c))(va_list args, int flags);
int _printf(const char *format, ...);
int print_char(va_list args, int flags);
int print_string(va_list args, int flags);
int print_percent(va_list args, int flags);
int print_int(va_list args, int flags);
int print_binary(va_list args, int flags);
int print_hex(va_list args, int flags);
int print_octal(va_list args, int flags);
int print_HEX(va_list args, int flags);
int print_uint(va_list args, int flags);
int print_S(va_list args, int flags);
int print_hex_char(char c);
int print_pointer(va_list args, int flags);
int print_reverse(va_list args, int flags);
int print_rot13(va_list args, int flags);

int print_hex_size_t(uintptr_t value);
int handle_flags(const char *format, int start, int end);
int is_flag(char c);

char *_strcpy(char *dest, const char *src);
int _strlen(char *s);
int is_spec(char c);
#endif
