/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:50:52 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/23 12:56:16 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	process_element(char *line, int *flag, char *element, int *arg)
{
	char	**color;

	if (!ft_strncmp(line, element, 2))
	{
		if (*flag)
			return (print_error(INVALID_ELEMENT));
		*flag = 1;
		color = ft_split(line + 1, ',');
		if (!(color[0]) || !(color[1]) || !(color[2]))
		{
			free_array(color);
			return (print_error(INVALID_ELEMENT_COLOR));
		}
		return (process_color(color, arg));
	}
	return (0);
}

int	has_floor_ceiling(char *line, int *arg, char *element, int *flag)
{
	return (process_element(line, flag, element, arg));
}
