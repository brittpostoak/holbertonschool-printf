#include <stdio.h>
#include <stdarg.h>
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
  if (format == NULL)
    {
            return (-1);
    }
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    count += printf("%c", c);
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    count += printf("%s", s);
                    break;
                }
                case '%':
                {
                    count += printf("%c", *format);
                    break;
                }
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    count += printf("%d", num);
                    break;
                }
                default:
                {
                    count += printf("%%%c", *format);
                    break;
                }
            }
        }
        else
        {
            count += printf("%c", *format);
        }
        format++;
    }
    va_end(args);
    return count;
}
