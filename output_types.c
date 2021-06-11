#include "libftprintf.h"

unsigned long	output_s(va_list *list, struct s_definition *d, char **s)
{
	va_list			src;
	unsigned long	u;

	va_copy(src, *list);
	if (ft_strlen(va_arg(*list, char *)) == -5)
		*s = ft_strdup("(null)");
	else
		*s = ft_strdup(va_arg(src, char *));
	u = display_s(d, *s, ft_strlen(*s));
	return (u);
}

unsigned long	output_p(va_list *list, struct s_definition *d, char **s)
{
	unsigned long	u;
	int				i;

	u = va_arg(*list, unsigned long);
	*s = ft_itoa_six(u);
	i = ft_strlen(*s);
	return (display_p(d, *s, i));
}

unsigned long	output_x(va_list *list, struct s_definition *d, char **s)
{
	unsigned long	u;
	int				i;

	u = va_arg(*list, unsigned int);
	if (d->type == 'x')
		*s = ft_itoa_six(u);
	else
		*s = ft_itoa_six_uppercase(u);
	i = ft_strlen(*s);
	return (display_d(d, *s, i));
}

unsigned long	output_d(va_list *list, struct s_definition *d, char **s)
{
	unsigned long	u;
	int				i;

	i = va_arg(*list, int);
	*s = ft_itoa(i);
	return (display_d(d, *s, ft_strlen(*s)));
}

unsigned long	output_u(va_list *list, struct s_definition *d, char **s)
{
	unsigned long	u;

	u = va_arg(*list, unsigned int);
	*s = ft_itoa_uint(u);
	return (display_d(d, *s, ft_strlen(*s)));
}
