#include "main.h"

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
    {'\0', NULL}
};
