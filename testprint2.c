#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
  int count = 0;
  va_list values;

  va_start(values, format);

  char *str = NULL;

  if (values != NULL) {
    str = va_arg(values, char *);
  } else {
    str = "";
  }

  while (*format) {
    if (*format == '%') {
      format++;
      switch (*format) {
        case 'c': {
          char c = va_arg(values, int);
          count += printf("%c", c);
          break;
        }
        case 's': {
          count += printf("%s", str);
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

  va_end(values);
  return count;
}

int main() {
  _printf(NULL);
  return 0;
}
