#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - a function to print anything
 * @format: input argument
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, j;
	char *str;
	va_list ap;

	va_start(ap, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				_putchar(va_arg(ap, int));
				break;
			case 's':
				str = va_arg(ap, char*);
				if (!str)
					return (-1);
				while (str && str[j])
				{
					_putchar(str[j]);
					j++;
				}
				break;
			case '%':
				if (format[i + 1] == '%')
					_putchar(va_arg(ap, int));
				break;
		} i++;
	} _putchar('\n');
	return (1);
}
