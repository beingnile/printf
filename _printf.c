#include "main.h"

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
	const char *p;

	count = 0;
	va_start(arg, format);
	if (format == NULL)
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			write(STDOUT_FILENO, p, 1);
			count++;
			continue;
		} else if (!*++p)
			return (0);
		--p;
		switch (*++p)
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
		}
	}
	va_end(arg);

	return (count);
}
