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
			write(STDOUT_FILENO, format, 1);
			count++;
			continue;
		}
		switch (*++format)
		{
			case '%':
				write(STDOUT_FILENO, "%", 1);
				count++;
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
			default:
				write(STDOUT_FILENO, --format, 1);
				count++;
				break;
		}
	}
	va_end(arg);

	return (count);
}
