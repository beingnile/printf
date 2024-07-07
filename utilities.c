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
