#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

void print_char(char c, size_t *char_count) {
    write(1, &c, 1);
    (*char_count)++;
}

void print_address(void *addr, size_t *total_count) {
    uintptr_t value = (uintptr_t)addr;
    char address_str[18];

    address_str[0] = '0';
    address_str[1] = 'x';

    int i;
    for (i = 0; i < 16; i++) {
        int digit = (value >> (4 * (15 - i))) & 0xF;
        address_str[i + 2] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    }
    address_str[18] = '\n';

    for (i = 0; i < 18; i++) {
        print_char(address_str[i], total_count);
    }
}

int main(void) {
    int var = 0;
    int *ptr = &var;
    size_t total = 0;

    // Print the address manually
    print_address(ptr, &total);

    printf("Total characters printed: %zu\n", total);
    return 0;
}

/*
 * format_checker - does what it's named
 * @s: can't remember what I needed this for, move on
 * 
 * @i: hiiii, i, do you remember the use I had for you? cause I don't 🥹🥹

int format_checker(const char *s, size_t i)
{
size_t len = _strlen(s);
char *str, c;
if (s == NULL)
return (0);
why did I even think of this??, such a silly idea, lol
str = (char *)malloc((len *sizeof(char)) + 1);
if (str == NULL)
return (0);

_strcpy(str, s);

if (sort(str[i + 1]) == 0)
return (1);
else
return (0);
}
*/


/**
 * ptr_spotify - spots functions for the pointer associated specifiers
 * @c: specifier whose function is to be identifed
 * Return: pointer to function spotted

size_t (*ptr_spotify(char c))(void *, size_t)
{
int i = 0;

ptr_spec pointer_spec[] = {
{'p', print_address},
{'\0', NULL}
};

while (pointer_spec[i].c != '\0')
{
if (c == pointer_spec[i].c)
return (pointer_spec[i].specify);
i++;
}
return (NULL);
}
*/


/*
 * struct pointer_specifiers - still don't mind me...I'll have some use soon
 * @c: I do the same thing as my sister above
 * @specify: me too (wish I had that black-faced side eyed emoji here)

typedef struct pointer_specifiers
{
char c;
size_t (*specify)(void *addr, size_t count);
} ptr_spec;
*/
