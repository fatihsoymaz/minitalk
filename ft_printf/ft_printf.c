/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:52:20 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/01/03 13:39:44 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format(va_list s, char c, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(s, int), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(s, int), count);
	else if (c == 's')
		ft_putstr(va_arg(s, char *), count);
	else if (c == 'u')
		ft_putunbr(va_arg(s, unsigned int), count);
	else if (c == 'x' || c == 'X')
		print_hex(va_arg(s, unsigned int), c, count);
	else if (c == 'p')
	{
		*count += write (1, "0x", 2);
		ft_putpointer(va_arg(s, unsigned long), count);
	}
	else if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	lst;

	va_start(lst, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			format(lst, s[i + 1], &count);
			i++;
		}
		else
			ft_putchar(s[i], &count);
		i++;
	}
	va_end(lst);
	return (count);
}
