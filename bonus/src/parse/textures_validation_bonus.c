/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_validation_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:10:23 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/24 11:55:51 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	verify_textures(t_config *input)
{
	if (!input->tex.west || !input->tex.east \
		|| !input->tex.north || !input->tex.south)
		return (print_error(INVALID_TEX));
	return (0);
}

static void	handle_texture(char *dir, int *flag, char **path)
{
	*flag = 1;
	*path = ft_strdup(dir);
}

static void	handle_textures(t_config *arg, char *dir, char *texture)
{
	if (ft_strncmp(texture, "NO ", 3) == 0)
		handle_texture(dir, &(arg->tex.north), &(arg->tex.north_path));
	else if (ft_strncmp(texture, "SO ", 3) == 0)
		handle_texture(dir, &(arg->tex.south), &(arg->tex.south_path));
	else if (ft_strncmp(texture, "WE ", 3) == 0)
		handle_texture(dir, &(arg->tex.west), &(arg->tex.west_path));
	else if (ft_strncmp(texture, "EA ", 3) == 0)
		handle_texture(dir, &(arg->tex.east), &(arg->tex.east_path));
}

int	has_texture(char *line, t_config *arg, char *texture, int *has_flag)
{
	char	*clean_line;
	int		fd;

	fd = -1;
	if (!ft_strncmp(line, texture, 3))
	{
		if (*has_flag)
			return (print_error(INVALID_TEX));
		clean_line = remove_whitespaces(line + 2, 0);
		if (ft_strncmp(clean_line + (ft_strlen(clean_line) - 4), \
								XPM_EXTENSION, 4))
		{
			free(clean_line);
			return (print_error(INVALID_TEX));
		}
		fd = verify_xpm_file(clean_line);
		handle_textures(arg, clean_line, texture);
		free(clean_line);
		if (fd < 0)
			return (print_error(INVALID_TEX));
		if (fd > 0)
			close(fd);
	}
	return (0);
}
