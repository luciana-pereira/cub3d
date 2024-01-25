/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 12:17:10 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	init_structure(t_config *input)
{
	input->px = 0;
	input->py = 0;
	input->player = 0;
	input->width = 0;
	input->height = 0;
	input->floor = 0;
	input->ceiling = 0;
	input->tex.north = 0;
	input->tex.south = 0;
	input->tex.west = 0;
	input->tex.east = 0;
	input->floor_color = 0;
	input->ceiling_color = 0;
}

void	init_settings(t_config *input, char **argv)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(strerror(errno));
	input->fd = fd;
}
