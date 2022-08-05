//#include "ft_printf.h"
# include <unistd.h>

int	ft_printf(const char *input, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == %)
		{
			len += checker(arg, input[i + 1]);
			i++;
		}
		else
		{
			len += putchar(input[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}

int main ()
{
    ft_printf("asdf");
    return (0);
}