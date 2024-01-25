/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:37:50 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/23 12:56:16 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	process_file_lines(t_config **input, char *line)
{
	char	*current_line;

	while (line)
	{
		current_line = remove_whitespaces(line);
		free(line);
		if (!verify_all_elements(current_line, *input))
		{
			free(current_line);
			return ;
		}
		free(current_line);
		if ((*input)->tex.north && (*input)->tex.south
			&& (*input)->tex.east && (*input)->tex.west
			&& (*input)->ceiling && (*input)->floor)
		{
			break ;
		}
		line = get_next_line((*input)->fd);
	}
}

int	read_and_process_file(t_config **input)
{
	char	*line;

	line = get_next_line((*input)->fd);
	if (line == NULL)
	{
		print_error(EMPTY_FILE);
		return (0);
	}
	process_file_lines(input, line);
	return (1);
}

int	verify_xpm_file(char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL || ft_strncmp(line, "/* XPM */", 9))
	{
		close (fd);
		return (-1);
	}
	free(line);
	return (fd);
}
