#include "main.h"

/**
 * print_char - Prints a char to stdout
 * @ap: Argument parameters
 *
 * Return: Number of characters printed
 */
int print_char(va_list ap)
{
	int c = va_arg(ap, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string to stdout
 * @ap: Argument parameters
 *
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
 * print_percent - Prints the percent character to stdout
 * @ap: Argument parameters
 *
 * Return: Number of characters printed
 */
int print_percent(va_list ap)
{
	char c = '%';
	(void) ap;

	return (write(1, &c, 1));
}

/**
 * _pow - functino that computes the value of x to the power of y
 * @x: integer to raise to the power
 * @y: integer used for the power
 *
 * Return: the value of x to the power of y
 */
int _pow(int x, int y)
{
	int tmp;

	if (y == 0)
		return (1);

	tmp = _pow(x, y / 2);
	if ((y % 2) == 0)
		return (tmp * tmp);

	else
	{
		if (y > 0)
			return (x * tmp * tmp);

		return ((tmp * tmp) / x);
	}
}

/**
 * print_int - Prints an integer
 * @ap: Argument parameters
 *
 * Return: Number of characters printed
 */
int print_int(va_list ap)
{
	int num = va_arg(ap, int);
	int len = 0, i = 0;
	char zero;
	int numCopy = num;
	int count = 0, digit, lenCopy;

	if (num == 0)
	{
		zero = '0';
		return (write(1, &zero, 1));
	}

	for (; numCopy != 0; len++)
		numCopy = numCopy / 10;

	if (num < 0)
		count += write(1, "-", 1);

	lenCopy = len - 1;
	for (; i < len; i++, lenCopy--)
	{
		digit = (num / _pow(10, lenCopy)) % 10;

		if (digit < 0)
			digit = -1 * digit;

		digit += '0';

		count += write(1, &digit, 1);
	}

	return (count);
}


