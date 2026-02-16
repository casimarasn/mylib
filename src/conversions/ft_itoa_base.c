/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:17:02 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/17 00:21:39 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base_len(long n, int base_len)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

static int	ft_is_valid_base(const char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_fill_str(char *str, long num, const char *base, int len)
{
	int	blen;

	blen = ft_strlen(base);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = base[0];
	while (num > 0)
	{
		str[--len] = base[num % blen];
		num /= blen;
	}
}

char	*ft_itoa_base(int n, const char *base)
{
	char	*str;
	int		len;
	long	num;

	if (!ft_is_valid_base(base))
		return (NULL);
	num = n;
	len = ft_base_len(num, ft_strlen(base));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_fill_str(str, num, base, len);
	return (str);
}
