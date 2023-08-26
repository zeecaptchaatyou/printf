#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <sys/types.h>
#include <wchar.h>
#include <stddef.h>
#define BUFF_SIZE 1024



/*function pointers function declaration*/
size_t (*i_spotify(char c))(ssize_t n, size_t count);
size_t (*str_spotify(char c))(char *s, size_t count);
size_t (*ui_spotify(char c))(size_t n, size_t count);
/*I'll deal with this later*/
size_t (*ptr_spotify(char c))(void *addr, size_t count);

/*conversion specifier functions*/
size_t print_binary(size_t n, size_t count);
size_t print_string(char *s, size_t count);
size_t print_char(char c, size_t count);
size_t print_octal(size_t n, size_t count);
size_t print_decimal(ssize_t n, size_t count);
size_t print_h_decimal(size_t n, size_t count);
size_t print_rot(char *s, size_t count);
size_t print_uppercase_h_decimal(size_t n, size_t count);
size_t print_u_int(size_t n, size_t count);
size_t print_reverse(char *s, size_t count);
size_t print_customstr(char *s, size_t count);
size_t print_address(void  *addr, size_t count);

/*random function's declarations*/
char *_strcpy(char *dest, const char *src);
ssize_t checker(ssize_t n, char base);
int num_length_counter(int n);
int _islower(char c);
int _isupper(char c);
char *toUpperCase(char *str);
void _putchar(char c);
int _strlen(char *s);
int pow_zee(int n);
int _isalpha(char c);
char *_itoa(ssize_t n, int base);
char *_u_itoa(size_t n, int base);
int _printf(const char *format, ...);
void recurse(char *s);
int sort(char c);
int check_format(char *s, size_t i);
char *S_u_itoa(size_t n, int base);


/*struct declarations*/

/**
 * struct int_specifiers - don't mind us
 * @c: conversion specifier
 * @specify: pointer to a function that executess specify
*/
typedef struct int_specifiers
{
char c;
size_t (*specify)(ssize_t i, size_t count);
} int_spec;

/**
 * struct u_int_specifiers - still don't mind me...I'll have some use soon
 * @c: I do the same thing as my sister above
 * @specify: me too (wish I had that black-faced side eyed emoji here)
*/
typedef struct u_int_specifiers
{
char c;
size_t (*specify)(size_t i, size_t count);
} u_int_spec;

/**
 * struct string_specifiers - still don't mind me...I'll have some use soon
 * @c: I do the same thing as my sister above
 * @specify: me too (wish I had that black-faced side eyed emoji here)
*/
typedef struct string_specifiers
{
char c;
size_t (*specify)(char *s, size_t count);
} str_spec;

#endif /*"MAIN_H"*/
