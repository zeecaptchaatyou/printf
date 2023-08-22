#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int printInt(int n);
int binary(int num);

int octal(int num);

#endif /* MAIN_H */
