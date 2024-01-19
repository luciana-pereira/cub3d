/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:33:11 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/19 10:54:02 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_lst	*read_map_lines(int fd, t_lst *node)
{
	char	*line;
	t_lst	*start;
	t_lst	*new;

	start = node;
	line = get_next_line(fd);
	while (line)
	{
		node->content = line;
		new = (t_lst *)malloc(sizeof(t_lst));
		new->next = NULL;
		new->content = NULL;
		node->next = new;
		node = node->next;
		line = get_next_line(fd);
	}
	if (fd > 0)
		close(fd);
	return (start);
}

static int	**process_map_data(t_lst *start, t_config **input)
{
	int	**map;

	start = remove_empty(start);
	if (verify_map(start, input, 1) == -1)
		print_error(INVALID_MAP);
	map = create_map(start, input);
	if (map == NULL)
		free_input((*input));
	free_map_lines(start);
	return (map);
}

int	**read_map(int fd, t_config **input, t_lst *node)
{
	t_lst	*start;
	int		**map;

	start = read_map_lines(fd, node);
	map = process_map_data(start, input);
	return (map);
}
