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
 * rev_string - reverses a string
 * @s: string to reverse
 *
 * Return: nothing
 */
void rev_string(char *s)
{
	int i = 0, len = strlen(s), tmp;

	if (len % 2)
	{
		for (; i <= len / 2; i++)
		{
			tmp = s[i];
			s[i] = s[len - 1 - i];
			s[len - 1 - i] = tmp;
		}
	}
	else
	{
		for (; i <= len / 2 - 1; i++)
		{
			tmp = s[i];
			s[i] = s[len - 1 - i];
			s[len - 1 - i] = tmp;
		}
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
	int len = 0, i = 0;
	char zero;
	int num = va_arg(ap, int);
	int numCopy = num;
	int modulus;
	char *strNum = NULL;

	if (num == 0)
	{
		zero = '0';
		return (write(1, &zero, 1));
	}

	for (; numCopy != 0; numCopy /= 10)
		len++;

	if (num > 0)
		strNum = malloc(len + 1);
	else if (num < 0)
		strNum = malloc(len + 2);

	if (strNum == NULL)
		return (-2);

	if (num < 0)
		strNum[len] = '-';

	for (; num != 0; num /= 10)
	{
		modulus = num % 10;
		if (modulus < 0)
			modulus = -1 * modulus;

		strNum[i] = modulus + '0';
		i++;
	}

	rev_string(strNum);
	return (write(1, strNum, strlen(strNum)));
}


