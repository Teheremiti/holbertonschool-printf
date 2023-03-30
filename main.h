#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
 * struct print_format -  structure used to print a correct format
 * @type: type of format
 * @f: printing function to call
 *
 */
typedef struct print_format
{
	char type;
	int (*f)(va_list);
} print_t;

int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_int(va_list);
int _pow(int, int);
int _printf(const char *format, ...);


#endif
