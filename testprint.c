#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
  int count = 0;
  va_list args;

  va_start(args, format);

  str = va_arg(values, char *);
	if (str == NULL)
		str = "(null)";

  while (*format) {
    if (*format == '%') {
      format++;
      switch (*format) {
        case 'c': {
          char c = va_arg(args, int);
          count += printf("%c", c);
          break;
        }
        case 's': {
          char *s = va_arg(args, char *);
          count += printf("%s", s);
          break;
        }
        case '%': {
          count += printf("%%");
          break;
	}
	case 'p': {
	_printf("%p\n", NULL);
	break;
        }
        default: {
          break;
        }
      }
    } else {
      count += printf("%c", *format);
    }
    format++;
  }

  va_end(args);
  return count;
}

int main() {
  _printf(NULL);
  return 0;
}
