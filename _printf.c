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
	int count, cval, dval;
	const char *p;
	char *sval;

	count = 0;
	va_start(arg, format);
	if (format == NULL)
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			if (write(STDOUT_FILENO, p, 1) < 0)
				return (-1);
			count++;
			continue;
		}
		switch (*++p)
		{
			case '%':
				if (write(STDOUT_FILENO, "%", 1) < 0)
					return (-1);
				count++;
				break;
			case 'c':
				cval = (char) va_arg(arg, int);
				if (write(STDOUT_FILENO, &cval, 1) < 0)
					return (-1);
				count++;
				break;
			case 'd':
				dval = va_arg(arg, int);
				count += write(STDOUT_FILENO, &dval, 1);
				break;
			case 's':
				sval = va_arg(arg, char *);
				if (sval == NULL)
					sval = "(null)";
				while (*sval)
				{
					if (write(STDOUT_FILENO, sval, 1) < 0)
						return (-1);
					count++;
					sval++;
				}
				break;
			default:
				if (write(STDOUT_FILENO, p, 1) < 0)
					return (-1);
				count++;
				break;
		}
	}
	va_end(arg);

	return (count);
}
