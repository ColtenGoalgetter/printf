#include "ft_printf.h"

int	ft_putchar(const char *c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	return (1);
}
