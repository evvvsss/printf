#include "libftprintf.h"

int	output(struct s_definition *d, va_list *list)
{
	unsigned long	u;
	char			*s;

	u = 0;
	s = NULL;
	if (d->type == 'd' || d->type == 'i')
		u = output_d(list, d, &s);
	else if (d->type == 'c')
		return (display_c(d, va_arg(*list, int)));
	else if (d->type == 's')
		u = output_s(list, d, &s);
	else if (d->type == 'p')
		u = output_p(list, d, &s);
	else if (d->type == 'u')
		u = output_u(list, d, &s);
	else if (d->type == 'x' || d->type == 'X')
		u = output_x(list, d, &s);
	else if (d->type == '%')
		return (display_c(d, '%'));
	if (s != NULL)
		free(s);
	return (u);
}
