/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:00:31 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/24 11:24:26 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	verify_colors(t_config *input)
{
	if (!input->ceiling)
		return (print_error(INVALID_CEILING));
	if (!input->floor)
		return (print_error(INVALID_FLOOR));
	return (0);
}

static int	is_valid_color(int red, int green, int blue)
{
	if ((red < 0 || red > 255) || (blue < 0 || blue > 255)
		|| (green < 0 || green > 255))
		return (print_error(INVALID_RGB_COLOR));
	return (0);
}

static int	convert_rgb(char **color)
{
	int	colors;
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(color[0]);
	green = ft_atoi(color[1]);
	blue = ft_atoi(color[2]);
	if (is_valid_color(red, green, blue) == -1)
		return (-1);
	colors = RGB_RED * red + RGB_GREEN * green + RGB_BLUE * blue;
	return (colors);
}

static char	**remove_whitespaces_color(char **color)
{
	char	*temp;
	int		index;

	index = 0;
	while (index < 3)
	{
		temp = remove_whitespaces(color[index], 0);
		free(color[index]);
		color[index] = temp;
		index++;
	}
	return (color);
}

int	process_color(char **color, int *arg)
{
	color = remove_whitespaces_color(color);
	if (!is_numeric(color[0]) || !is_numeric(color[1]) || !is_numeric(color[2]))
	{
		free_array(color);
		return (print_error(INVALID_ELEMENT_COLOR));
	}
	*arg = convert_rgb(color);
	free_array(color);
	if (*arg == -1)
		return (-1);
	return (0);
}
