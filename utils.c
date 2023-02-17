/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:02:55 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/02/15 15:03:04 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result);
}

void	do_new_line(int pid)
{
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR1);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
	kill(pid, SIGUSR1);
	usleep(130);
	kill(pid, SIGUSR2);
	usleep(130);
}
