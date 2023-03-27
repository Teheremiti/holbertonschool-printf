#include <unistd.h>
#include <stdarg.h>

typedef struct print_format
{
	char type;
	void (*f)(va_list);
} print_t;

int _printf(const char *format, ...);
