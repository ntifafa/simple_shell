#include "main.h"

/**
 * _printf - stripped down printf version that handles string formats only
 * @format: specifier
 * Return: void
*/

void _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
		/*handle format specifier*/
		format++; /*move to next char*/

		if (*format == 's') /*handle string argument*/
		{
			char *str = va_arg(args, char *);

			while (*str) /*print each string char*/
			{
			_putchar(*str);
			str++;
			}
		}
		else
		{
			_putchar('?');  /*print when format specifier is unsupported*/
		}
		}
		else
		{
		_putchar(*format);  /*print char*/
		}
		format++;
	}
	va_end(args);
}
