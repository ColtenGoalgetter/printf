#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	i;
	int	ret;

	va_start(ap, format);
	i = 0;
	ret = 0;

	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i+1]))
		{
			ret += ft_printf_arg(format, i, ap);
			i++;
		}
		else
			ret += ft_putchar(&format[i]);
		i++;
	}
	va_end(ap);
	return(ret);
}

int	ft_printf_arg(const char *format, int i, va_list ap)
{
	int	ret;

	ret = 0;
	if (format[i+1] == '%')
		ret += ft_putchar("%");
	else if (format[i+1] == 'c')
		ret += ft_putchar(va_arg(ap, char *));
	else if (format[i+1] == 's')
		ret += ft_putstr(va_arg(ap, char *));
	else if (format[i+1] == 'd' || format[i+1] == 'i')
		ret += ft_putnbr_base(va_arg(ap, int), dec);
	else if (format[i+1] == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), dec));
	else if (format[i+1] == 'x' || format[i+1] == 'X')
		if (format[i+1] == 'x')
			return (ft_putnbr_base(va_arg(ap, unsigned long int), hex));
		else
			return (ft_putnbr_base(va_arg(ap, int), HEX));
	else if (format[i+1] == 'p')
		return (ft_putstr("0x") + ft_putstr(va_arg(ap, void *)));
	return (ret);
}
