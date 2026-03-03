/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:30:42 by msedeno-          #+#    #+#             */
/*   Updated: 2026/03/03 18:31:11 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u_fd(long int n, int fd)
{
	char	buffer[10];
	int		printed;
	int		i;

	printed = 0;
	i = 0;
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i > 0)
		printed += ft_putchar_fd(buffer[--i], fd);
	return (printed);
}
