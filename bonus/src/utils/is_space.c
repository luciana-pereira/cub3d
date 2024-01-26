/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:15:47 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/24 15:00:51 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	is_space(int c)
{
	return (c == '\t' || c == '\v' || c == '\f' || c == '\r' || c == ' ' || \
		c == '\n');
}

char	*trim_end_space(char *str)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(str) - 1;
	while (end > start && is_space(str[end]))
		end--;
	str[end + 1] = '\0';
	return (str);
}
