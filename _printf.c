#include "main.h"

/**
 * _printf - Produces output according to a format.
 *
 * @format: The character syring to be produced.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list arg;
	int count, cval;
	const char *p;
	char *sval;

	count = 0;
	va_start(arg, format);
	if (format == NULL)
		exit(1);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			count += write(STDOUT_FILENO, p, 1);
			continue;
		}
		switch (*++p)
		{
			case 'c':
				cval = va_arg(arg, int);
				count += write(STDOUT_FILENO, (char *) &cval, 1);
				break;
			case 's':
				for (sval = va_arg(arg, char *); *sval; sval++)
				{
					count += write(STDOUT_FILENO, sval, 1);
				}
				break;
			default:
				count += write(STDOUT_FILENO, p, 1);
				break;
		}
	}
	va_end(arg);

	return (count);
}
