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
	print_t spec[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL}
	};
	int i, j;
	int count = 0;

	va_list ap;

	va_start(ap, format);

	i = 0;
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			char chr = format[i];

			count += write(1, &chr, 1);
		}

		j = 0;
		while (spec[j].type != '\0')
		{
			if (format[i] == '%' && format[i + 1] == spec[j].type)
			{
				count += spec[j].f(ap);
				i++;
			}
			j++;
		}
		i++;
	}

	va_end(ap);
	return (count);
}
