/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:17:40 by msedeno-          #+#    #+#             */
/*   Updated: 2026/03/03 16:14:15 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_searchtype_fd(va_list vargs, char c, int fd)
{
	unsigned int	print;

	print = 0;
	if (c == 'c')
		print += ft_putchar_fd(va_arg(vargs, int), fd);
	else if (c == 's')
		print += ft_putstr_fd(va_arg(vargs, char *), fd);
	else if (c == 'd' || c == 'i')
		print += ft_putnbr_fd(va_arg(vargs, int), fd);
	else if (c == 'u')
		print += ft_putnbr_u_fd(va_arg(vargs, unsigned int), fd);
	else if (c == '%')
		print += ft_putchar_fd('%', fd);
	else if (c == 'p')
		print += puthex_p_fd((unsigned long long)va_arg(vargs,
					unsigned long long), fd);
	else if (c == 'x')
		print += puthex_lower_fd((unsigned int)va_arg(vargs, unsigned int), fd);
	else if (c == 'X')
		print += puthex_upper_fd((unsigned int)va_arg(vargs, unsigned int), fd);
	return (print);
}

int	ft_fprintf(int fd, char const *s, ...)
{
	va_list			vargs;
	unsigned int	i;
	unsigned int	printed;

	printed = 0;
	va_start(vargs, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			printed += ft_searchtype_fd(vargs, s[i + 1], fd);
			i += 2;
		}
		else
		{
			printed += ft_putchar_fd(s[i], fd);
			i++;
		}
	}
	va_end(vargs);
	return (printed);
}
