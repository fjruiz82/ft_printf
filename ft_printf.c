//#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

int char_printer (int c)
{
	write (1,&c,1);
	return (1);
}

int str_printer (char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		write(1,&str[i],1);
		i++;
	}
	return (i);
}

void set_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		set_ptr (ptr / 16);
		set_ptr (ptr % 16);
	}
	else
	{
			if (ptr <= 9)
				char_printer(ptr);
			else
				char_printer(ptr - 10 + 'a');
	}
}

int ptr_printer (unsigned long long ptr)
{
	int len;

	len = 0;
	write (1,"0x",2);
	if (ptr == 0)
	{
		write(1,"0",1);
	}
	else
	{
		set_ptr(ptr);
	}
	return (len);
}
static int	ft_nlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	j;
	char			*tmp;

	tmp = (char *)malloc(ft_nlen(n) + 1);
	if (tmp == 0)
		return (0);
	i = ft_nlen(n);
	j = n;
	if (n < 0)
	{
		j = -n;
		tmp[0] = '-';
	}
	tmp[i] = '\0';
	tmp[i - 1] = '0';
	while (j > 0)
	{
		i--;
		tmp[i] = j % 10 + 48;
		j /= 10;
	}
	return (tmp);
}

int int_printer (int n)
{
	int len;
	char *num;

	len = 0;
	num = ft_itoa(n);
	len = str_printer(num);
	free (num);
	return (len);
}

static int	ft_u_nlen(unsigned long n)
{
	int	i;

	i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	int				i;
	//unsigned int	j;
	char			*tmp;

	tmp = (char *)malloc(ft_u_nlen(n) + 1);
	if (tmp == 0)
		return (0);
	//i = ft_u_nlen(n);
	//j = n;
	/*if (n < 0)
	{
		j = -n;
		tmp[0] = '-';
	}*/
	tmp[i] = '\0';
	tmp[i - 1] = '0';
	while (n != 0)
	{
		tmp[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (tmp);
}

int u_int_printer (int n)
{
	int len;
	char *num;

	len = 0;
	num = ft_uitoa(n);
	len = str_printer(num);
	free (num);
	return (len);
}

int checker (va_list args, const char key)
{
	int len;

	len = 0;
	if (key == 'c')
		len += char_printer (va_arg(args, int));
	else if (key == 's')
		len += str_printer (va_arg(args, char *));
	else if (key == 'p')
		len += ptr_printer (va_arg(args, unsigned long long));
	else if (key == 'd' || key == 'i')
		len += int_printer (va_arg(args, int));
	else if (key == 'u')
		len += unsigned_printer (va_arg(args, unsigned int));
	else if (key == 'x' || key == 'X')
		len += hex_printer (va_arg(args, unsigned int), key);
	else if (key == '%')
		len += percent_printer ();
	return (len);
}

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
		if (input[i] == '%')
		{
			len += checker(args, input[i + 1]);
			i++;
		}
		else
		{
			len += char_printer(input[i]);
		}
		i++;
	}
	va_end(args);
	printf("\n%d",len);
	return (len);
}

int	main(void)
{
	char *str = "Hola mundo";
	char c = 'a';
	int x = 512345454;

	printf("%s", str);
	ft_printf("%s\n", str);
	return (0);
}