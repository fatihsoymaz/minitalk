/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:03:35 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/02/15 16:40:14 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_receiving_signal(int signal)
{
	static int	bit = 7;
	static int	set = 0;

	if (signal == SIGUSR1)
		set += (1 << bit);
	else
		set += (0 << bit);
	if (bit == 0)
	{
		ft_printf("%c", set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
	signal(SIGUSR1, ft_receiving_signal);
	signal(SIGUSR2, ft_receiving_signal);
	while (1)
		pause();
	return (0);
}
