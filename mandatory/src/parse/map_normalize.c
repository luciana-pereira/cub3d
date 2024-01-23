/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:54:56 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/23 12:56:16 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdio.h>

static int content_normalizer(char **content, int size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc((size + 1) * sizeof(char));
	if (!temp)
		return (-1);
	while ((*content)[i] != '\0' && (*content)[i] != '\n')
	{
		temp[i] = (*content)[i];
		i++;
	}
	while (i < size)
	{
		temp[i] = ' ';
		i++;
	}
	temp[i] = '\0';
	free(*content);
	(*content) = temp;
	return (0);
}

int	map_normalizer(char ***map, t_config **input)
{
	int	i;

	i = -1;
	while ((*map)[++i] != NULL)
		process_map_line((*map)[i], 
	input);
	i = -1;
	while ((*map)[++i] != NULL)
	{
		if(ft_strlen((*map)[i]) != (*input)->width)
			if(content_normalizer(&(*map)[i], (*input)->width) == -1)
				return(-1);
	}
	return (0);
}

int	map_checker(char **map)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if ((map[row][col] == '0' || ft_strchr("NSEW", map[row][col])) \
				&& ((row == 0 || !map[row + 1])
					|| (col == 0)
					|| !map[row][col + 1]
					|| map[row][col + 1] == ' '
					|| map[row][col - 1] == ' '
					|| map[row + 1][col] == ' '
					|| map[row - 1][col] == ' '))
				return (-1);
			col++;
		}
		row++;
	}
	return (0);
}