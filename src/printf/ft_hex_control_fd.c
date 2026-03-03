/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_control_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:09:01 by msedeno-          #+#    #+#             */
/*   Updated: 2026/03/03 16:10:10 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	puthex_p_fd(unsigned long long num, int fd)
{
	char	*digits;
	int		printed;

	printed = 0;
	if (!num)
	{
		printed += ft_putstr_fd("(nil)", fd);
		return (printed);
	}
	printed += ft_putstr_fd("0x", fd);
	digits = "0123456789abcdef";
	if (num < 16)
		printed += ft_putchar_fd(digits[num], fd);
	if (num >= 16)
	{
		printed += puthex_lower_fd(num / 16, fd);
		printed += ft_putchar_fd(digits[num % 16], fd);
	}
	return (printed);
}

int	puthex_lower_fd(unsigned long long num, int fd)
{
	char	*digits;
	int		printed;

	printed = 0;
	digits = "0123456789abcdef";
	if (num < 16)
		printed += ft_putchar_fd(digits[num], fd);
	else if (num >= 16)
	{
		printed += puthex_lower_fd(num / 16, fd);
		printed += ft_putchar_fd(digits[num % 16], fd);
	}
	return (printed);
}

int	puthex_upper_fd(unsigned long long num, int fd)
{
	char	*digits;
	int		printed;

	printed = 0;
	digits = "0123456789ABCDEF";
	if (num < 16)
		printed += ft_putchar_fd(digits[num], fd);
	else if (num >= 16)
	{
		printed += puthex_upper_fd(num / 16, fd);
		printed += ft_putchar_fd(digits[num % 16], fd);
	}
	return (printed);
}
