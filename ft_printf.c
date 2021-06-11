#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list				list;
	int					len;
	int					i;
	struct s_definition	d;

	i = 0;
	len = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		struct_init(&d);
		if (format[i] == '%')
		{
			i++;
			i += check_flag((char *)(format + i), &d);
			i += check_digit((char *)(format + i), &d, &list);
			i += check_type((char *)(format + i), &d);
			len += output(&d, &list);
		}
		else if (++len)
			write(1, &format[i++], 1);
	}
	va_end(list);
	return (len);
}

// int main ()
// {
// 	int		a = 0;
// 	int		b = 0;
// 	char	c = 'a';
// 	int		d = 2147483647;
// 	int		e = -2147483648;
// 	int		f = 42;
// 	int		g = 25;
// 	int		h = 4200;
// 	int		i = 8;
// 	int		j = -12;
// 	int		k = 123456789;
// 	int		l = 0;
// 	int		m = -12345678;
// 	char	*n = "abcdefghijklmnop";
// 	char	*o = "-a";
// 	char	*p = "-12";
// 	char	*q = "0";
// 	char	*r = "%%";
// 	char	*s = "-2147483648";
// 	char	*t = "0x12345678";
// 	char	*u = "-0";
// 	int		nata;

// 	a = f;
// 	b = g;
	
// 	nata = printf(" hello %10.12d hello\n ", 1, -1);
	
// 	 printf("\n%d\n",nata);
// 	ft_printf(" %-3.2d %10.12d\n", 1, -1);
	
// 	// while (1) {}
// // 	ft_printf("%d, %d",l, m);
// 	//ft_printf("%p %x\n", NULL, 0);
// 	//  printf("%-9.*d\n", 6, 5666);
// 	//  printf("%-9.*d\n", 6, 5666);
// 	// printf("%6.3d\n", -2147483648);
// 	//  ft_printf("%03.1u", 6);
// 	//   printf("%.15p\n", (void *)209590960);
// 	//   ft_printf("%.15p", (void *)209590960);
//  }
