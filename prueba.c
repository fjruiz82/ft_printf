//#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int putchar (int c)
{
	write (1,&c,1);
	return (1);
}

int	ft_printf(const char *input)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	//va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			//len += checker(args, input[i + 1]);
			i++;
		}
		else
		{
			len += putchar(input[i]);
		}
		i++;
	}
	//va_end(args);
    printf("%d",len);
	return (len);
}

int	main(void)
{
	ft_printf("asdf");
	return (0);
}


/*#include <unistd.h>

int main ()
{
    char str[] = "Hola que pasa";
    int i;
    i = 0;
    while (str[i])
    {
        write(1,&str[i],1);
        i++;
    }
    return (0);    
}*/