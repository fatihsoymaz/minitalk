/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:54:00 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/01/03 13:42:19 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *sign, ...);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putunbr(unsigned int nb, int *count);
void	print_hex(unsigned int value, char c, int *count);
void	ft_putpointer(unsigned long ptr, int *count);
#endif
