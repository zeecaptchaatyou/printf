#include "main.h"

/**
 * sort - sorts the format string of my printf function
 * according to my specifications
 * @c: string to be sorted
 * Return: 1 if the sort is what I want:yawning_face: else 0;
*/
int sort(char c)
{
if (c == 'b' || c == 'x' || c == 'X' || c == 'o'
|| c == 'u' || c == 'p')
return (1);
else if (c == 's' || c == 'S' || c == 'r' || c == 'R')
return (2);
else if (c == 'c')
return (3);
else if (c == '%')
return (4);
else
return (0);
}
