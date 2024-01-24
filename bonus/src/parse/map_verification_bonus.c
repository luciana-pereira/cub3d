/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:54:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/24 15:05:10 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <stdio.h>

void	print_matrix(char **matrix);

int	verify_players(t_config *input)
{
	if (!input->width)
		return (0);
	if (input->player > 1 || input->player == 0)
	{
		print_error(INVALID_PLAYER);
		return (0);
	}
	return (1);
}

int	verify_all_elements(char *line, t_config *input)
{
	if (line[0] && !verify_line(line))
	{
		print_error(INVALID_CHARAC);
		return (0);
	}
	if (has_texture(line, input, "NO ", &input->tex.north) || \
		has_texture(line, input, "SO ", &input->tex.south) || \
		has_texture(line, input, "WE ", &input->tex.west) || \
		has_texture(line, input, "EA ", &input->tex.east) || \
		has_floor_ceiling(line, &input->floor_color, "F ", &input->floor) || \
		has_floor_ceiling(line, &input->ceiling_color, "C ", &input->ceiling))
		return (0);
	return (1);
}

int	process_map_line(char *line_map, t_config **input)
{
	if ((*input)->width < ft_strlen(line_map))
		(*input)->width = ft_strlen(line_map);
	(*input)->height++;
	return (0);
}

int	verify_map(char **map, t_config **input)
{
	if (!map)
		return (-1);
	if (map_normalizer(&map, input) == -1)
		return (-1);
	if (map_checker(map) == -1)
		return (-1);
	return (0);
}

void	print_matrix(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		printf("%s\n", matrix[i]);
		while (matrix[i][j] != '\0')
		{
			printf("%i ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
