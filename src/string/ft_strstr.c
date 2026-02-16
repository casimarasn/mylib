/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 11:31:04 by msedeno-          #+#    #+#             */
/*   Updated: 2026/02/15 11:31:40 by msedeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr(char *s, char *finder)
{
	int	i;
	int	j;

	i = 0;
	if (!finder[0])
		return (1);
	while (s[i])
	{
		j = 0;
		while (s[i + j] && finder[j] && s[i + j] == finder[j])
			j++;
		if (!finder[j])
			return (1);
		i++;
	}
	return (0);
}
