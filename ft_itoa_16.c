#include "libftprintf.h"

static size_t	len(unsigned long n)
{
	size_t	k;

	k = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		n = n / 16;
		k++;
	}
	return (k - 1);
}

char	*ft_itoa_six(unsigned long n)
{
	char	*d;
	size_t	i;

	i = len(n);
	d = malloc((i + 2) * sizeof(char));
	if (!d)
		return (NULL);
	d[i + 1] = '\0';
	if (i == 0)
		d[0] = '0';
	while (i > 0)
	{
		if ((n % 16) < 10)
			d[i--] = (n % 16) + 48;
		else
			d[i--] = (n % 16) + 87;
		n = n / 16;
	}
	if ((n % 16) < 10)
		d[i--] = (n % 16) + 48;
	else
		d[i--] = (n % 16) + 87;
	n = n / 16;
	return (d);
}

char	*ft_itoa_six_uppercase(unsigned long n)
{
	char	*d;
	size_t	i;

	i = len(n);
	d = malloc((i + 2) * sizeof(char));
	if (!d)
		return (NULL);
	d[i + 1] = '\0';
	if (i == 0)
		d[0] = '0';
	while (i > 0)
	{
		if ((n % 16) < 10)
			d[i--] = (n % 16) + 48;
		else
			d[i--] = (n % 16) + 55;
		n = n / 16;
	}
	if ((n % 16) < 10)
		d[i--] = (n % 16) + 48;
	else
		d[i--] = (n % 16) + 55;
	n = n / 16;
	return (d);
}
