/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:54:42 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 17:24:44 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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

static int	is_valid_map_block(char *line_map, int inside_map)
{
	if (line_map == NULL || line_map[0] == 0)
	{
		if (inside_map == 1)
			return (0);
	}
	else if (inside_map == 0)
	{
		free(line_map);
		return (-1);
	}
	return (1);
}

static int	process_map_line(char *line_map, t_config **input)
{
	if ((*input)->width < ft_strlen(line_map))
		(*input)->width = ft_strlen(line_map);
	(*input)->height++;
	return (0);
}

int	verify_map(t_lst *map, t_config **input, int inside_map)
{
	char	*line_map;
	int		result;

	while (map && map->next)
	{
		line_map = remove_whitespaces(map->content);
		result = is_valid_map_block(line_map, inside_map);
		if (result == -1)
			return (-1);
		else if (result == 1)
			process_map_line(line_map, input);
		free(line_map);
		map = map->next;
	}
	return (0);
}
