#include "libftprintf.h"

int	check_flag(char *format, struct s_definition *d)
{
	int	i;

	i = 0;
	while (format[i] == '-' || format[i] == '0')
	{
		if (format[i] == '-')
			d->minus = 1;
		else if (format[i] == '0')
			d->zero = 1;
		i++;
	}
	return (i);
}

int	check_digit_star(char *f, struct s_definition *d, va_list *list, int *i)
{
	d->width = va_arg(*list, int);
	if (d->width < 0)
	{
		d->width = -d->width;
		d->minus = 1;
	}
	(*i)++;
	if (f[*i] == '.')
		*i = *i + 1 + check_precision((char *)(f + *i + 1), d, list);
	return (*i);
}

int	check_digit(char *format, struct s_definition *d, va_list *list, int i)
{
	char	*str;

	if (format[i] == '.')
		return (1 + i + check_precision((char *)(format + i + 1), d, list));
	if (format[i] == '*')
		return (check_digit_star(format, d, list, &i));
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		str[i] = format[i];
		i++;
	}
	str[i] = '\0';
	if (d->width == 0)
		d->width = ft_atoi(str);
	free(str);
	if (format[i] == '.')
		i = 1 + i + check_precision((char *)(format + i + 1), d, list);
	return (i);
}

int	check_precision(char *format, struct s_definition *d, va_list *list)
{
	int		i;
	char	*str;

	i = 0;
	if (format[i] == '*')
	{
		d->precision = va_arg(*list, int);
		return (1);
	}
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (i == 0)
		d->precision = 0;
	str = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		str[i] = format[i];
		i++;
	}
	str[i] = '\0';
	if (d->precision == -1)
		d->precision = ft_atoi(str);
	free(str);
	return (i);
}

int	check_type(char *format, struct s_definition *d)
{
	d->type = format[0];
	return (1);
}
