#include "libftprintf.h"

void	struct_init(struct s_definition *d)
{
	d->zero = 0;
	d->type = 'a';
	d->width = 0;
	d->minus = 0;
	d->precision = -1;
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
			write_char(' ', &n);
		write(1, &c, u);
		return (n + u);
	}
}

int	display_s(struct s_definition *d, char *s, int u)
{
	int	n;

	n = 0;
	if ((d->precision >= 0))
		return (display_s_precision(d, &s, &u, &n));
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
			write_char(' ', &n);
		write(1, s, u);
		return (n + u);
	}
}

int	display_s_precision(struct s_definition *d, char **s, int *u, int *n)
{
	if ((d->minus == 1) && (d->width > 0))
	{
		if (d->precision < *u)
			*u = d->precision;
		write(1, *s, *u);
		while ((*u)++ < d->width)
			write(1, " ", 1);
		return (--(*u));
	}
	if (d->precision < *u)
		*u = d->precision;
	while ((d->width)-- > *u)
		write_char(' ', n);
	write(1, *s, *u);
	*n += *u;
	return (*n);
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
			write_char(' ', &n);
	}
	else if (d->zero == 1)
	{
		write(1, "0x", 2);
		while ((d->width)-- > (u + 2))
			write_char('0', &n);
		write(1, s, u);
	}
	else
	{
		while ((d->width)-- > (u + 2))
			write_char(' ', &n);
		write(1, "0x", 2);
		write(1, s, u);
	}
	return (n + u + 2);
}
