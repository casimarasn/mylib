/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 00:34:55 by casimarasn        #+#    #+#             */
/*   Updated: 2026/03/03 16:06:31 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	int			printed;

	num = n;
	printed = 0;
	if (num == -2147483648)
	{
		printed = ft_putstr_fd("-2147483648", fd);
		return (-1);
	}
	if (num < 0)
	{
		printed += ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num > 9)
	{
		printed = ft_putnbr_fd (num / 10, fd);
		printed += ft_putchar_fd ((num % 10) + '0', fd);
	}
	else
		printed += ft_putchar_fd(num + '0', fd);
	return (printed);
}
