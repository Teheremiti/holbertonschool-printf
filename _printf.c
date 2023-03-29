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
		{'d', print_int},
		{'\0', NULL}
	};
	int i, j;
	int count = 0;
	va_list ap;

	va_start(ap, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (j = 0; spec[j].type != '\0'; j++)
			{
				if (format[i + 1] == spec[j].type)
				{
					count += spec[j].f(ap);
					i++;
					break;
				}
				if (spec[j + 1].type == '\0')
					count += spec[j].f(ap);
			}
		}
		else
		{
			char chr = format[i];

			count += write(1, &chr, 1);
		}
	}
	va_end(ap);
	return (count);
}
