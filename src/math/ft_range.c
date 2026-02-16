/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 00:09:09 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/17 00:09:30 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	int	*tab;

	i = 0;
	if (start > end)
		len = (start - end) + 1;
	else
		len = (end - start) + 1;
	tab = malloc(len * (sizeof (int)));
	while (i < len)
	{
		tab[i] = start;
		if (start > end)
			start --;
		else if (end > start)
			start++;
		i++;
	}
	return (tab);
}