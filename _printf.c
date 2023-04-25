#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function.
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
va_list list;
va_start(list, format);
int printed_chars = vsnprintf(NULL, 0, format, list);
va_end(list);
if (printed_chars < 0)
{
return (-1);
}
char *buffer = malloc(printed_chars + 1);
if (buffer == NULL)
{
return (-1);
}
va_start(list, format);
printed_chars = vsnprintf(buffer, printed_chars + 1, format, list);
va_end(list);
write(1, buffer, printed_chars);
free(buffer);
return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists.
 * @buffer: Array of chars.
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)
{
for (int i = 0; i < *buff_ind; i++)
{
putchar(buffer[i]);
}
*buff_ind = 0;
}

