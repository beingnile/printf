#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int handle_specifier(const char **format, va_list arg);

/* Functions that help with printing */
int print_bin(va_list arg);
int print_char(va_list arg);
int print_int(va_list arg);
int print_str(va_list arg);
int print_unsigned_base(va_list arg, int base, int uppercase);

/* Helper functions */
int _itoa(int src, char *str);

#endif
