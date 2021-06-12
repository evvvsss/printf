#include "libftprintf.h"

char	*cut_str(char *s, int start, size_t len)
{
	size_t	i;

	i = 0;
	len--;
	if (!s)
		return (NULL);
	while (s[start + i] != '\0' && len > 0)
	{
		s[i] = s[start + i];
		i++;
		len--;
	}
	s[i] = '\0';
	return (s);
}

long	ft_strlen(const char *s)
{
	long	i;

	i = 0;
	if (!s)
		return (-5);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	write_char(char a, int *n)
{
	write(1, &a, 1);
	(*n)++;
}

void	struct_init(struct s_definition *d)
{
	d->zero = 0;
	d->type = 'a';
	d->width = 0;
	d->minus = 0;
	d->precision = -1;
}

char	*ft_strdup(const char *s)
{
	size_t		len;
	size_t		i;
	char		*d;

	i = 0;
	len = ft_strlen(s);
	d = malloc(sizeof(*s) * (len + 1));
	if (!d)
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
