#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>

typedef struct print_format
{
	char type;
	int (*f)(va_list);
} print_t;

int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int _printf(const char *format, ...);

#endif
