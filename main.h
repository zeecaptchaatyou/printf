#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);

/* Handing %d and %i */
int printfInteger(const char *format, ...);
int print_integer(int n);

/* Handle Binary */
int binary(int num);

/* Handle Octals */
int octal(int num);

#endif /* MAIN_H */
