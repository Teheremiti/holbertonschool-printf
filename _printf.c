#include "main.h"

/**
 * _printf - Produce output according to a format
 *
 * @format: Character string. Contains the print directives for each format
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0;

	va_start(ap, format);

	while (format != NULL && format[i] != '\0')
	{
		i++;
	}

	va_end(ap);

	return (0);
}
