#include "main.h"

/**
 * printfInt - Prints an integer to the standard output.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed.
 */
int printfInt(int n)
{
	char buffer[20];
	int length = 0;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		length++;
	}
	do {
		buffer[length] = (n % 10) + '0';
		n /= 10;
		length++;
	} while (n > 0);

	for (int i = 0; i < length / 2; i++)
	{
		char temp = buffer[i];

		buffer[i] = buffer[length - i - 1];

		buffer[length - i - 1] = temp;
	}
	write(1, buffer, length);
	return (length);
}
