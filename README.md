![Holberton School logo](https://user-images.githubusercontent.com/120781178/229278297-98c6e4b7-f15f-4788-a893-15cb97f10351.png)

# :mortar_board: C - printf

First group project at Holberton School : implement our own simplified version of the **printf** function in C.

**Name:** 
_printf - Formats and prints data

**Synopsis**
#include "main.h"
int _printf(const char * format, ...);

**Files**
main.h - Header file with all the prototypes and a structure 
print_func.c - Contains functions that print for each type of data
_printf.c

**Description**
The _printf function produces output according to a format and returns the total number of characters printed. It is called by a variable number of arguments and writes output to stdout, the standard output stream.
The format string controls the output and specifies how subsequent arguments are converted for it.


### man _printf
[_printf man page](https://github.com/Teheremiti/holbertonschool-printf/blob/master/man_3_printf)
[_printf man page](https://github.com/Teheremiti/holbertonschool-printf/blob/master/man_3_printf.1) (roff mark up language)


## Requirements
-   All the files will be compiled on Ubuntu 20.04 LTS using  
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c`
- The code should respect the [Betty](https://github.com/holbertonschool/Betty/wiki) coding style : a linter specific to Holberton School
- Global variables are forbidden
- Each file should contain only five or less functions with less than forty lines per function
-  Handling buffer, flag characters, field width, precision, and length modifiers is optional
- The _printf function should handle the following format specifiers :
-- `%c`
-- `%s`
-- `%d`
-- `%i`
-- `%%`

### Authorized functions and macros
-   `write` 
-   `malloc` 
-   `free` 
-   `va_start` 
-   `va_end`
-   `va_copy`
-   `va_arg`



## Exemples

	root@id:/holbertonschool-printf# cat main.c
	#include <stdio.h>
	#include "main.h"
	
	/**
	 * main - Check the code
	 *   
	 * Return: Always 0
	*/
	  
	int main(void)
	{
		int len, len2;

		len = _printf("Let's printf a simple sentence.\n");
		len2 = printf("Let's printf a simple sentence.\n");
		printf("\n");

		_printf("Character:[%c]\n", 'H');
		printf("Character:[%c]\n\n", 'H');

		_printf("String:[%s]\n", "I am a string !");
		printf("String:[%s]\n\n", "I am a string !");

		_printf("Integer:[%d, %i]\n", len, -len);
		printf("Integer:[%d, %i]\n\n", len2, -len2);

		_printf("Percent:[%%]\n");
		printf("Percent:[%%]\n\n");

		_printf("Unknown:[%r]\n");
		printf("Unknown:[%r]\n");

		return (0);
	}
	root@id:/holbertonschool-printf# gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c -o _printf
	root@id:/holbertonschool-printf# ./_printf
	Let's try to printf a simple sentence.
	Let's try to printf a simple sentence.

	Character:[H]
	Character:[H]

	String:[I am a string !]
	String:[I am a string !]

	Integer:[32, -32]
	Integer:[32, -32]

	Percent:[%]
	Percent:[%]

	Unknown:[%r]
	Unknown:[%r]
	root@id:/holbertonschool-printf#

## Valgrind

    root@id:/holbertonschool-printf# valgrind ./_printf
    ==19647== Memcheck, a memory error detector
    ==19647== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==19647== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
    ==19647== Command: ./_printf
    ==19647==
    [...]
    ==19647==
    ==19647== HEAP SUMMARY:
    ==19647== in use at exit: 0 bytes in 0 blocks
    ==19647== total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
    ==19647==
    ==19647== All heap blocks were freed -- no leaks are possible
    ==19647==
    ==19647== For lists of detected and suppressed errors, rerun with: -s
    ==19647== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    root@0241fe6ce683:/holbertonschool-printf#

## Flowchart

![_printf flowchart](https://user-images.githubusercontent.com/120781178/229278406-a18ebe71-d7aa-4fcd-b40c-b9d26eb9c0c5.png)

## AUTHORS

Written by **Teheremiti Tuiaiho** and **Vladimir Davidov**
