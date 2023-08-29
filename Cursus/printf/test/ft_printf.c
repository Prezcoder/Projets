
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		i++;
	return (write(1, s, i));
}

int	ft_putnbr_hexa(uintptr_t n)
{
	const char	*base;
	int			temp;

	temp = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		temp += ft_putnbr_hexa(n / 16);
		temp += ft_putnbr_hexa(n % 16);
	}
	else
		temp += write(1, &base[n], 1);
	return (temp);
}

int	ft_putnbr(int n)
{
	const char	*base;
	int			nbr_len;

	nbr_len = 0;
	base = "0123456789";
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		nbr_len += write(1, "-", 1);
		nbr_len += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		nbr_len += ft_putnbr(n / 10);
		nbr_len += ft_putnbr(n % 10);
	}
	else
		nbr_len += write(1, &base[n], 1);
	return (nbr_len);
}

int	ft_letter(va_list args, const char format)
{
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'x')
		return (ft_putnbr_hexa(va_arg(args, unsigned int)));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			length += ft_letter(args, s[i++ + 1]);
		else
			length += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (length);
}

int	main(void)
{
	char	*str;
	int		x;

	x = -1754;
	str = "allo mon petit";
	ft_printf("%d\n", ft_printf("%x\n%d\n%s\n", x, x, str));

	printf("%d\n", printf("%x\n%d\n%s\n", x, x, str));
}