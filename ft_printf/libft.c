/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:12:42 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/01/02 15:55:24 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	*count += write (1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
	{
		*count += (write (1, "(null)", 6));
		return ;
	}
	*count += write (1, str, ft_strlen(str));
}

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', count);
		ft_putchar('2', count);
		ft_putnbr(147483648, count);
	}
	else if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
		ft_putnbr(nb, count);
	}
	else if (nb > 9)
	{
		ft_putnbr((nb / 10), count);
		ft_putnbr((nb % 10), count);
	}
	else
		ft_putchar((nb + 48), count);
}

void	ft_putunbr(unsigned int n, int *count)
{
	if (n > 9)
	{
		ft_putunbr((n / 10), count);
		ft_putunbr((n % 10), count);
	}
	else
		ft_putchar((n + 48), count);
}
