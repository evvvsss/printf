#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define MAX 922337203685477580
# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

struct	s_definition
{
	char	type;
	int		width;
	int		minus;
	int		zero;
	int		precision;
};
int				ft_printf(const char *format, ...);
void			struct_init(struct s_definition *d);
int				check_precision(char *format,
					struct s_definition *d, va_list *list);
int				check_digit(char *format, struct s_definition *d, va_list *str);
int				check_flag(char *format, struct s_definition *d);
int				ft_atoi(const char *str);
int				check_type(char *format, struct s_definition *d);
char			*ft_itoa(int n);
long			ft_strlen(const char *s);
int				output(struct s_definition *d, va_list *list);
char			*ft_strdup(const char *s);
char			*ft_itoa_six(unsigned long n);
char			*ft_itoa_uint(unsigned int n);
char			*ft_itoa_six_uppercase(unsigned long n);
int				display_d(struct s_definition *d, char *s, long u);
int				display_c(struct s_definition *d, char c);
int				display_s(struct s_definition *d, char *s, int u);
int				display_p(struct s_definition *d, char *s, int u);
char			*cut_str(char *s, int start, size_t len);
unsigned long	output_s(va_list *list, struct s_definition *d, char **s);
unsigned long	output_p(va_list *list, struct s_definition *d, char **s);
unsigned long	output_x(va_list *list, struct s_definition *d, char **s);
unsigned long	output_d(va_list *list, struct s_definition *d, char **s);
unsigned long	output_u(va_list *list, struct s_definition *d, char **s);

#endif