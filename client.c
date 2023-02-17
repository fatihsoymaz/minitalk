/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:10:31 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/02/15 20:33:59 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(int pid, char *str)
{
	unsigned char	c;
	int				i;
	int				j;
	int				bit;

	i = 0;
	while (str[i])
	{
		c = str[i];
		j = 7;
		while (j >= 0)
		{
			bit = (c >> j) & 1;
			if (bit)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
	do_new_line(pid);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("You entered incorrectly, you need to enter three arguments");
		return (0);
	}
	ft_send_signal(ft_atoi(av[1]), av[2]);
	return (0);
}
