/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:53:29 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/01/03 13:40:33 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int value, char c, int *count)
{
	if (value >= 16)
	{
		print_hex(value / 16, c, count);
		print_hex(value % 16, c, count);
	}
	else
	{
		if (value > 9 && c == 'X')
			ft_putchar(value + 55, count);
		else if (value > 9 && c == 'x')
		{
			ft_putchar(value +87, count);
		}
		else
			ft_putchar(value + 48, count);
	}
}

void	ft_putpointer(unsigned long ptr, int *count)
{
	if (ptr > 15)
		ft_putpointer((ptr / 16), count);
	ft_putchar("0123456789abcdef"[ptr % 16], count);
}
