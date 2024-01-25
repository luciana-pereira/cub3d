/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:27:06 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 14:07:27 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	*allocate_map_row(t_config **input)
{
	int	*row_ptr;

	row_ptr = (int *)malloc(sizeof(int) * ((*input)->width + 1));
	if (!row_ptr)
		return (NULL);
	return (row_ptr);
}

static int	allocate_and_get_element(t_config **input, char *map, \
										size_t row, size_t col)
{
	int	element;

	if (map[col] == '\0')
		element = get_element(' ', input, row, col);
	else
		element = get_element(map[col], input, row, col);
	if (element == -1)
		return (-1);
	return (element);
}

static int	*populate_map_row(char **map, t_config **input, int *int_map, \
								size_t row)
{
	size_t	col;

	int_map = allocate_map_row(input);
	if (!int_map)
		return (NULL);
	col = -1;
	while (++col < (*input)->width)
	{
		int_map[col] = allocate_and_get_element(input, map[row], row, col);
		if (int_map[col] == -1)
		{
			free(int_map);
			return (NULL);
		}
	}
	return (int_map);
}

static int	**populate_map(char **map, t_config **input)
{
	int		**int_map;
	size_t	row;

	row = 0;
	int_map = allocate_map_memory(input);
	if (!int_map)
		return (NULL);
	while (row < (*input)->height)
	{
		int_map[row] = populate_map_row(map, input, int_map[row], row);
		if (!int_map[row])
		{
			free_2d_array(int_map, row);
			return (NULL);
		}
		row++;
	}
	return (int_map);
}

int	**create_map(char **map, t_config **input)
{
	int	**int_map;

	int_map = populate_map(map, input);
	if (!int_map || !verify_players(*input))
	{
		free_2d_array(int_map, (*input)->height);
		return (NULL);
	}
	return (int_map);
}
