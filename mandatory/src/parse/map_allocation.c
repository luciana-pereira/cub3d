/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:27:06 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/22 09:03:34 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	*allocate_map_row(t_config **input)
{
	int	*row_ptr;

	row_ptr = (int *)malloc(sizeof(int) * (*input)->width);
	if (!row_ptr)
		return (NULL);
	return (row_ptr);
}

static int	allocate_and_get_element(t_config **input, t_lst *start, \
													size_t row, size_t col)
{
	int	element;

	if (col + 1 >= ft_strlen(start->content))
		element = get_element(' ', input, row, col);
	else
		element = get_element(start->content[col], input, row, col);
	if (element == -1)
		return (-1);
	return (element);
}

static int	**populate_map_row(t_lst *start, t_config **input, int **map, \
																	size_t row)
{
	size_t	col;

	map[row] = allocate_map_row(input);
	if (!map[row])
		return (NULL);
	col = -1;
	while (++col <= (*input)->width)
	{
		map[row][col] = allocate_and_get_element(input, start, row, col);
		if (map[row][col] == -1)
		{
			free_2d_array(map, row + 1);
			return (NULL);
		}
	}
	return (map);
}

static int	**populate_map(t_lst *start, t_config **input, int **map)
{
	size_t	row;

	row = 0;
	while (row < (*input)->height)
	{
		map = populate_map_row(start, input, map, row);
		if (!map)
			return (NULL);
		start = start->next;
		row++;
	}
	return (map);
}

int	**create_map(t_lst *start, t_config **input)
{
	int	**map;

	map = allocate_map_memory(input);
	if (!map)
		return (NULL);
	map = populate_map(start, input, map);
	if (!map || !verify_players(*input))
	{
		free_2d_array(map, (*input)->height);
		return (NULL);
	}
	return (map);
}
