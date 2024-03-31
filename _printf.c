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
	int count, cval, dval, strlen;
	const char *p;
	char *sval, *buffer;

	count = 0;
	buffer = malloc(sizeof(char) * 514);
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
			case 'i':
				dval = va_arg(arg, int);
				strlen = _itoa(dval, buffer);
				if (write(STDOUT_FILENO, buffer, strlen) < 0)
					return (-1);
				count += strlen;
				free(buffer);
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

/**
 * _itoa - Converts an integer into a string.
 * write() acts weirdly with values of type int,
 * This function solves that.
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
	start = str;
	end = str;

	if (src < 0)
	{
		*str++ = '-';
		end++;
		len++;
		src = -src;
	}
	do
	{
		*end++ = (src % 10) + '0';
		len++;
		src /= 10;
	} while (src != 0);
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
