#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list				list;
	int					len;
	int					i;
	struct s_definition	d;

	i = 0;
	len = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		struct_init(&d);
		if (format[i] == '%')
		{
			i++;
			i += check_flag((char *)(format + i), &d);
			i += check_digit((char *)(format + i), &d, &list, 0);
			i += check_type((char *)(format + i), &d);
			len += output(&d, &list);
		}
		else
			write_char(format[i++], &len);
	}
	va_end(list);
	return (len);
}
