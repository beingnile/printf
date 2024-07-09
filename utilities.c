#include "main.h"

/**
 * _itoa - Converts an integer into a null-terminated string.
 * write() acts weirdly with values of type int, this function
 * solves that by changing the int to a string representation.
 *
 * @src: Int to convert.
 * @str: Buffer to store string.
 *
 * Return: Length of @str.
 */
int _itoa(int src, char *str)
{
	char *start, *end;
	int len = 0;
	long temp = src; /* To handle the overflowing INT_MIN */

	start = str;
	end = str;

	if (src < 0)
	{
		*str = '-';
		end++;
		start++;
		len++;
		temp = -temp;
	}

	do {
		*end++ = (temp % 10) + '0';
		len++;
		temp /= 10;
	} while (temp != 0);
	*end = '\0';
	end--;

	while (start < end)
	{
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;

		start++;
		end--;
	}

	return (len);
}

/**
 * print_pointer - Handles the p conversioon specifier
 *
 * @arg: Variadic list with format pointer
 *
 * Return: The number of characters written
 */
int print_pointer(va_list arg)
{
	int count = 0;
	void *pointer = va_arg(arg, void*);
	char *buffer;
	unsigned long p = (unsigned long)pointer;
	char *hex_digits = "0123456789abcdef";
	int index = 0;
	int rem = 0;
	int i = 0;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
		return (-1);

	if (pointer == NULL)
	{
		count += write(STDOUT_FILENO, "(nil)", 5);
		return (count);
	}

	while (p != 0)
	{
		rem = p % 16;
		*(buffer + index++) = *(hex_digits + rem);
		p /= 16;
	}

	count += write(STDOUT_FILENO, "0x", 2);

	for (i = index - 1; i >= 0; i--)
		count += write(STDOUT_FILENO, (buffer + i), 1);

	free(buffer);

	return (count);
}
