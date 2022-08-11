/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:51:11 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/08/11 12:47:05 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_u_nlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	int		i;
	char	*tmp;

	i = ft_u_nlen(n);
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (tmp == 0)
		return (0);
	tmp[i] = '\0';
	while (n != 0)
	{
		tmp[i - 1] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (tmp);
}

int	u_int_printer(int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		len = str_printer(num);
		free(num);
	}
	return (len);
}
