#include "libftprintf.h"

static int	ft_sign(const char *str, size_t *i, int *sign)
{
	while (!(str[*i] >= 48 && str[*i] <= 57) && *sign == 0)
	{
		if (str[*i] == '-')
			*sign = -1;
		else if (str[*i] == '+')
			*sign = 1;
		else
			return (0);
		(*i)++;
	}
	return (1);
}

static int	ft_digit(const char *str, size_t *i, int *sign)
{
	size_t	k;
	size_t	c;

	k = 0;
	c = 0;
	while (str[*i] >= 48 && str[*i] <= 57 && str[*i] !='\0')
	{
		if (k++ > 17 && ((str[*i] - 48 > 7 && c == MAX) || c > MAX))
		{
			if (*sign == -1)
				return (-10);
			else
				return (-1);
		}
		c = c * 10 + str[*i] - 48;
		(*i)++;
	}
	return (c);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			f;
	int			sign;

	sign = 0;
	i = 0;
	if (ft_sign(str, &i, &sign) == 0)
		return (0);
	f = ft_digit(str, &i, &sign);
	if (f == -1)
		return (-1);
	else if (f == -10)
		return (0);
	else
	{
		if (sign == -1)
			return (-f);
		else
			return (f);
	}
}
