#include "main.h"
#include <stdio.h>

/**
 * _printf - Produces output according to a format.
 *
 * @format: The character string to be produced.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int count;

	count = 0;
	va_start(arg, format);
	if (format == NULL || (*(format + 0) == '%' && *(format + 1) == '\0'))
		return (-1);
	for (; *format; format++)
	{
		if (*format != '%')
		{
			count += write(STDOUT_FILENO, format, 1);
			continue;
		}
		count += handle_specifier(&format, arg);
	}
	va_end(arg);

	return (count);
}

/**
 * handle_specifier - Handles the conversion specifiers
 *
 * @format: Pointer to pointer to format string
 * @arg: Variadic arguments used by printers
 *
 * Return: The number of characters written
 */
int handle_specifier(const char **format, va_list arg)
{
	int count = 0;

	switch (*++(*format))
	{
		case '%':
			count += write(STDOUT_FILENO, "%", 1);
			break;
		case 'b':
			count += print_bin(arg);
			break;
		case 'c':
			count += print_char(arg);
			break;
		case 'd':
		case 'i':
			count += print_int(arg);
			break;
		case 's':
			count += print_str(arg);
			break;
		case 'o':
			count += print_unsigned_base(arg, 8, 0);
			break;
		case 'u':
			count += print_unsigned_base(arg, 10, 0);
			break;
		case 'x':
			count += print_unsigned_base(arg, 16, 0);
			break;
		case 'X':
			count += print_unsigned_base(arg, 16, 1);
			break;
		default:
			count += write(STDOUT_FILENO, --(*format), 1);
			break;
	}

	return (count);
}
