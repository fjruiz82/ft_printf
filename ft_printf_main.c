#include "ft_printf.h"
# include <stdio.h>

int	main(void)
{
	char *str = "Hola mundo";
	char c = 'a';
	int x = 512343452;

	printf("%c\n", c);
	ft_printf("%c\n", c);
		printf("%s\n", str);
	ft_printf("%s\n", str);
	printf("%p\n", str);
	ft_printf("%p\n", str);
	printf("%i\n", x);
	ft_printf("%i\n", x);
	printf("%u\n", x);
	ft_printf("%u\n", x);
	printf("%x\n", x);
	ft_printf("%x\n", x);
	printf("%%\n");
	ft_printf("%%\n");
	return (0);
}
