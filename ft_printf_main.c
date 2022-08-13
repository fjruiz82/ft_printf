#include "ft_printf.h"
# include <stdio.h>

int	main(void)
{
	char *str = "Hola mundo";
	char c = 'a';
	int x = 0;

	printf("char: %c\n", c);
	ft_printf("-char: %c\n", c);
	printf("string: %s\n", str);
	ft_printf("-string: %s\n", str);
	printf("\n%d\n",printf("puntero: %p\n", str));
	printf("\n%d\n",ft_printf("-puntero: %p\n", str));
	printf("entero: %i\n", x);
	ft_printf("-entero: %i\n", x);
	printf("unsigned: %u\n", x);
	ft_printf("-unsigned: %u\n", x);
	printf("hexadecimal: %x\n", x);
	ft_printf("-hexadecimal: %x\n", x);
	printf("Por ciento:%%\n");
	ft_printf("- Por ciento: %%\n");
	printf("\n%d\n",printf("asdf"));
	return (0);
}
