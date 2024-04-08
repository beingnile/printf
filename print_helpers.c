#include "main.h"

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
	write(STDOUT_FILENO, &cval, 1);
	count++;

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
		write(STDOUT_FILENO, sval, 1);
		count++;
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
	char buffer[11];

	dval = va_arg(arg, int);
	strlen = _itoa(dval, buffer);
	write(STDOUT_FILENO, buffer, strlen);

	return (strlen);
}
