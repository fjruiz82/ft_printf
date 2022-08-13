/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:08:07 by fruiz-ca          #+#    #+#             */
/*   Updated: 2022/08/13 14:50:34 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
int		checker(va_list args, const char key);
int		char_printer(int c);
int		str_printer(char *str);
int		ptr_printer(unsigned long ptr);
void	set_ptr(unsigned long ptr);
int		int_printer(int n);
char	*ft_itoa(int n);
int		u_int_printer(int n);
char	*ft_uitoa(unsigned int n);
int		hex_printer(unsigned int n, const char key);
void	put_hex(unsigned int n, const char key);
int		hex_len(unsigned int n);
int		percent_printer(void);

#endif
