#include "main.h"

/**
 * print_bin - Prints out a binary representation
 * according to a format specifier
 *
 * @arg: Character to print in binary form
 *
 * Return: The number of characters printed
 */
int print_bin(va_list arg)
{
	int bits, started; /* Number of bits in an unsigned int */
	int count = 0;
	int i = 0;
	unsigned int num = va_arg(arg, int);

	if (num == 0)
		count += write(STDOUT_FILENO, "0", 1);
	else
	{
		started = 0; /* Keeping tack of significant bits */
		bits = sizeof(unsigned int) * 8;

		for (i = bits - 1; i >= 0; i--)
		{
			if ((num >> i) & 1)
			{
				started = 1;
				count += write(STDOUT_FILENO, "1", 1);
			} else if (started)
			{
				count += write(STDOUT_FILENO, "0", 1);
			}
		}
	}

	return (count);
}

/**
 * print_char - Prints out characters according to
 * a format specifier
 *
 * @arg: Character to print
 *
 * Return: The number of characters printed
 */
int print_char(va_list arg)
{
	int count = 0;
	int cval;

	cval = (char) va_arg(arg, int);
	count += write(STDOUT_FILENO, &cval, 1);

	return (count);
}

/**
 * print_str - Prints out a string according to
 * a format specifier
 *
 * @arg: String to print
 *
 * Return: The number of characters printed
 */
int print_str(va_list arg)
{
	int count = 0;
	char *sval;

	sval = va_arg(arg, char *);
	if (sval == NULL)
		sval = "(null)";
	while (*sval)
	{
		count += write(STDOUT_FILENO, sval, 1);
		sval++;
	}

	return (count);
}

/**
 * print_int - Prints out integers according to
 * a format specifier
 *
 * @arg: Integers to print
 *
 * Return: The number of characters printed
 */
int print_int(va_list arg)
{
	int dval, strlen;
	char *buffer;

	if ((buffer = malloc(sizeof(char) * 1024)) == NULL)
		return (-1);
	dval = va_arg(arg, int);
	strlen = _itoa(dval, buffer);
	write(STDOUT_FILENO, buffer, strlen);

	free(buffer);
	return (strlen);
}

/**
 * print_unsigned_base - Prints n unsigned integer under
 * specified base
 *
 * @arg: Integers to print
 * @base: Base to print in
 * @uppercase: To handle X specifically
 *
 * Return: Number of characters printed
 */
int print_unsigned_base(va_list arg, int base, int uppercase)
{
	unsigned int num = va_arg(arg, int);
	int count = 0;
	int rem = 0;
	int index = 0;
	int i;
	char *buffer;
	char *hex_digits = (uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";

	if ((buffer = malloc(sizeof(char) * 1024)) == NULL)
		return (-1);
	if (num == 0)
		count += write(STDOUT_FILENO, "0", 1);
	else
	{
		while (num != 0)
		{
			rem = num % base;
			if (base == 16)
				*(buffer + index++) = *(hex_digits + rem);
			else
				*(buffer + index++) = (rem < 10) ? rem + '0' : rem - 10 + 'a';
			num /= base;
		}

		for (i = index - 1; i >= 0; i--)
			count += write(STDOUT_FILENO, (buffer + i), 1);
	}

	free(buffer);
	return (count);
}
