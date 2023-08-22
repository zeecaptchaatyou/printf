#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED_ARG(x) (void)(x)
#define BUFFER_SIZE 1024

/* FLAGS */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* SIZES */
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct FormatSpec - Struct FormatSpec
 *
 * @specifier: The format specifier.
 * @handler: The function handler associated.
 */
struct FormatSpec
{
	char specifier;
	int (*handler)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct FormatSpec FormatSpec_t - Typedef for struct FormatSpec
 */
typedef struct FormatSpec FormatSpec_t;

int _printf(const char *format, ...);
int handle_print_format(const char *format, int *idx, va_list args,
		char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTION HANDLERS ******************/

/* Functions to handle characters and strings */
int handle_char(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int handle_string(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int handle_percent(va_list args, char buffer[], int flags, int width,
		int precision, int size);

/* Functions - handle numbers */
int handle_int(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int handle_binary(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int handle_unsigned(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int handle_octal(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int handle_hexadecimal(va_list args, char buffer[], int flags, int width,
		int precision, int size);
int handle_hexa_upper(va_list args, char buffer[], int flags, int width,
		int precision, int size);

int handle_hexa(va_list args, char map_to[], char buffer[], int flags,
		char flag_ch, int width, int precision, int size);

/* Function - handle non-printable characters */
int handle_non_printable(va_list args, char buffer[], int flags, int width,
		int precision, int size);

/* Function - handle memory addresses */
int handle_pointer(va_list args, char buffer[], int flags, int width,
		int precision, int size);

/* Functions - handle other specifiers */
int get_flags(const char *format, int *idx);
int get_width(const char *format, int *idx, va_list args);
int get_precision(const char *format, int *idx, va_list args);
int get_size(const char *format, int *idx);

/* Function - print a string in reverse */
int handle_reverse(va_list args, char buffer[], int flags, int width,
		int precision, int size);

/* Function - print a string in ROT13 */
int handle_rot13string(va_list args, char buffer[], int flags, int width,
		int precision, int size);

/* Handling Width */
int write_char(char c, char buffer[], int flags, int width, int precision,
		int size);
int write_number(int is_positive, int index, char buffer[], int flags,
		int width, int precision, int size);
int write_num(int index, char bff[], int flags, int width, int precision,
		int length, char padding, char extra_char);
int write_pointer(char buffer[], int index, int length, int width, int flags,
		char padding, char extra_char, int padding_start);
int write_unsigned(int is_negative, int index, char buffer[], int flags,
		int width, int precision, int size);

/* UTILITIES */
int is_printable_char(char c);
int append_hexa_code(char c, char dest[], int index);
int is_digit_char(char c);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#endif /* MAIN_H */

