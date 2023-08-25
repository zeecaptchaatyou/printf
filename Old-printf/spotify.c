#include "main.h"

/**
 * i_spotify - full meaning is "spot specifier", you grab
 * @c: conversion specifier
 * Return: pointer to function spotted
*/
size_t (*i_spotify(char c))(ssize_t, size_t)
{
int i = 0;

int_spec specs[] = {
{'d', print_decimal},
{'i', print_decimal},
{'\0', NULL}
};
while (specs[i].c != '\0')
{
if (c == specs[i].c)
return (specs[i].specify);
i++;
}
return (NULL);
}

/**
 * ui_spotify - spots the function for unsigned data types
 * @c: specifier whose function is to be identified
 * Return: pointer to function spotted
*/
size_t (*ui_spotify(char c))(size_t, size_t)
{
int i = 0;

u_int_spec uspecs[] = {
{'b', print_binary},
{'o', print_octal},
{'u', print_u_int},
{'x', print_h_decimal},
{'X', print_uppercase_h_decimal},
{'\0', NULL}
};
while (uspecs[i].c != '\0')
{
if (c == uspecs[i].c)
return (uspecs[i].specify);
i++;
}
return (NULL);
}

/**
 * str_spotify - spots functions for the string associated specifiers
 * @c: specifier whose function is to be identifed
 * Return: pointer to function spotted
*/
size_t (*str_spotify(char c))(char *, size_t)
{
int i = 0;

str_spec string_spec[] = {
{'s', print_string},
{'S', print_customstr},
{'r', print_reverse},
{'R', print_rot},
{'\0', NULL}
};

while (string_spec[i].c != '\0')
{
if (c == string_spec[i].c)
return (string_spec[i].specify);
i++;
}
return (NULL);
}

