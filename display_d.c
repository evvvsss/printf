#include "libftprintf.h"

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
		return (display_d_precision(d, &s, &u, &n));
	else if (d->minus == 1 && (d->precision <= u))
		return (display_d_minus(d, &s, &u));
	else if (d->zero == 1 && (d->precision < u) && d->precision <= -1)
		return (display_d_zero(d, &s, &u, &n));
	else
		return (display_d_width(d, &s, &u, &n));
}

int	display_d_precision(struct s_definition *d, char **s, long *u, int *n)
{
	int	i;

	i = 0;
	while (((d->width) > (d->precision)) && d->minus != 1)
	{
		(d->width)--;
		write_char(' ', n);
	}
	if (*s[0] == '-')
		(*u)++;
	if (*s[0] == '-')
		write(1, "-", 1);
	while ((d->precision) > (*u + i++))
		write_char('0', n);
	if (*s[0] == '-')
		*s = cut_str(*s, 1, *u);
	write(1, *s, ft_strlen(*s));
	while (((d->width)-- > (d->precision)) && d->minus == 1)
		write_char(' ', n);
	*n += *u;
	return (*n);
}

int	display_d_zero(struct s_definition *d, char **s, long *u, int *n)
{
	if (*s[0] == '-')
		(*u)++;
	if (*s[0] == '-')
		write(1, "-", 1);
	while (((*n)++ < (d->width - *u)) && ((d->width - *u) > 0))
		write(1, "0", 1);
	if (*s[0] == '-')
		*s = cut_str(*s, 1, *u);
	write(1, *s, ft_strlen(*s));
	return (--(*n) + *u);
}

int	display_d_minus(struct s_definition *d, char **s, long *u)
{
	if (*s[0] == '-')
		(*u)++;
	write(1, *s, *u);
	while ((*u)++ < d->width)
		write(1, " ", 1);
	return (--(*u));
}

int	display_d_width(struct s_definition *d, char **s, long *u, int *n)
{
	if (*s[0] == '-')
		(*u)++;
	while ((d->width)-- > *u)
	{
		write(1, " ", 1);
		(*n)++;
	}
	write(1, *s, *u);
	return (*n + *u);
}
