/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 01:34:56 by lucperei          #+#    #+#             */
/*   Updated: 2023/12/10 04:24:26 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	str_reverse_compare(const char *str1, const char *str2, size_t n)
{
	unsigned int	last_str1;
	unsigned int	last_str2;

	last_str1 = 0;
	last_str2 = 0;
	if (!str1 || !str2)
		return (0);
	last_str1 = ft_strlen(str1) - 1;
	last_str2 = ft_strlen(str2) - 1;
	while (--n && last_str1 && last_str2 && str1[last_str1] == str2[last_str2])
	{
		last_str1--;
		last_str2--;
	}
	return ((unsigned char)str1[last_str1] - (unsigned char)str2[last_str2]);
}
