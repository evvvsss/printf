#include "libftprintf.h"

void	struct_init(struct s_definition *d)
{
	d->zero = 0;
	d->type = 'a';
	d->width = 0;
	d->minus = 0;
	d->precision = -1;
}

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

int	check_digit(char *format, struct s_definition *d, va_list *list)
{
	int		i;
	char	*str;

	i = 0;
	if (format[i] == '.')
	{
		i = 1 + i + check_precision((char *)(format + i + 1), d, list);
		return (i);
	}
	if (format[i] == '*')
	{
		d->width = va_arg(*list, int);
		if (d->width < 0)
		{
			d->width = -d->width;
			d->minus = 1;
		}
		i++;
		if (format[i] == '.')
			i = 1 + i + check_precision((char *)(format + i + 1), d, list);
		return (i);
	}
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
	{
		d->precision = 0;
		return (0);
	}
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

int	display_d(struct s_definition *d, char *s, long u)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	if (s[0] == '-')
	{
		if (d->precision != -1)
			d->precision++;
		u--;
	}
	if ((d->precision == 0) && (s[0] == '0') && u--)
		s[0] = '\0';
	if ((d->precision > u))
	{	
		while (((d->width) > (d->precision)) && d->minus != 1)
		{
			(d->width)--;
			write(1, " ", 1);
			n++;
		}
		if (s[0] == '-')
			u++;
		if (s[0] == '-')
			write(1, "-", 1);
		while ((d->precision) > (u + i))
		{
			write(1, "0", 1);
			i++;
			n++;
		}
		if (s[0] == '-')
			s = cut_str(s, 1, u);
		write(1, s, ft_strlen(s));
		while (((d->width)-- > (d->precision)) && d->minus == 1)
		{
			write(1, " ", 1);
			n++;
		}
		n = n + u;
		return (n);
	}
	else if (d->minus == 1 && (d->precision <= u))
	{
		if (s[0] == '-')
			u++;
		write(1, s, u);
		while (u++ < d->width)
			write(1, " ", 1);
		return (--u);
	}
	else if (d->zero == 1 && (d->precision < u) && d->precision <= -1)
	{
		if (s[0] == '-')
			u++;
		if (s[0] == '-')
			write(1, "-", 1);
		while ((n++ < (d->width - u)) && ((d->width - u) > 0))
			write(1, "0", 1);
		if (s[0] == '-')
			s = cut_str(s, 1, u);
		write(1, s, ft_strlen(s));
		return (--n + u);
	}
	else
	{
		if (s[0] == '-')
			u++;
		while ((d->width)-- > u)
		{
			write(1, " ", 1);
			n++;
		}
		write(1, s, u);
		return (n + u);
	}
}

int	display_c(struct s_definition *d, char c)
{
	int	u;
	int	n;

	u = 1;
	n = 0;
	if (d->minus == 1)
	{
		write(1, &c, u);
		while (u++ < d->width)
			write(1, " ", 1);
		return (--u);
	}
	else
	{
		while ((d->width)-- > u)
		{
			write(1, " ", 1);
			n++;
		}
		write(1, &c, u);
		return (n + u);
	}
}

int	display_s(struct s_definition *d, char *s, int u)
{
	int	n;

	n = 0;
	if ((d->precision >= 0))
	{
		if ((d->minus == 1) && (d->width > 0))
		{
			if (d->precision < u)
				u = d->precision;
			write(1, s, u);
			while (u++ < d->width)
				write(1, " ", 1);
			return (--u);
		}
		if (d->precision < u)
			u = d->precision;
		while ((d->width)-- > u)
		{
			write(1, " ", 1);
			n++;
		}
		write(1, s, u);
		n = n + u;
		return (n);
	}
	else if (d->minus == 1)
	{
		write(1, s, u);
		while (u++ < d->width)
			write(1, " ", 1);
		return (--u);
	}
	else
	{
		while ((d->width)-- > u)
		{
			write(1, " ", 1);
			n++;
		}
		write(1, s, u);
		return (n + u);
	}
}

int	display_p(struct s_definition *d, char *s, int u)
{
	int	n;

	n = 0;
	if (d->minus == 1)
	{
		write(1, "0x", 2);
		write(1, s, u);
		while ((d->width)-- > (u + 2))
		{
			write(1, " ", 1);
			n++;
		}
	}
	else if (d->zero == 1)
	{
		write(1, "0x", 2);
		while ((d->width)-- > (u + 2))
		{
			write(1, "0", 1);
			n++;
		}
		write(1, s, u);
	}
	else
	{
		while ((d->width)-- > (u + 2))
		{
			write(1, " ", 1);
			n++;
		}
		write(1, "0x", 2);
		write(1, s, u);
	}
	return (n + u + 2);
}
