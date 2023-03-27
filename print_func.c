#include "main.h"

/**
 * print_char - Print a char to stdout
 * @ap: Argument parameters
 * Return: Number of characters printed
 */
int print_char(va_list ap)
{
	int c = va_arg(ap, int);
	char *null = "(null)";

	return (write(1, &c, 1));
}

/**
 * print_string - Print a string to stdout
 * @ap: Argument parameters
 * Return: Number of characters printed
 */
int print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	char *null = "(null)";

	if (s == NULL)
		return (write(1, null, strlen(null)));

	return (write(1, s, strlen(s)));
}

/**
 * print_percent - Print the percent character to stdout
 * @ap: Argument parameters
 * Return: Number of characters printed
 */
int print_percent(va_list ap)
{
	char c = '%';
	(void) ap;

	return (write(1, &c, 1));
}
