#include "libftprintf.h"

char	*cut_str(char *s, int start, size_t len)
{
	char	*b;
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
