#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


int	main(void)
{
	char	*str;
	int		x;

	x = 10;
	str = "allo";
	ft_printf("%s", str);
	ft_printf("%d\n", ft_printf("%s", str));
	printf("%s", str);
	printf("%d\n", printf("%s", str));
}