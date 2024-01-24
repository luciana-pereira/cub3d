/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:33:11 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/24 15:03:03 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"
#include <stdio.h>

static void	free_lst(t_lst *map_line);

static t_lst	*read_map_lines(int fd, t_lst *node)
{
	char	*line;
	t_lst	*head;
	t_lst	*new;
	int		map_lines;

	head = node;
	map_lines = 0;
	line = get_next_line(fd);
	if (!line)
	{
		free(head);
		head = NULL;
	}
	while (line && map_lines >= 0)
	{
		node->content = trim_end_space(line);
		new = (t_lst *)malloc(sizeof(t_lst));
		new->next = NULL;
		new->content = NULL;
		node->next = new;
		node = node->next;
		if (check_line(line) >= 0)
			line = get_next_line(fd);
		else
		{
			if (fd > 0)
				close(fd);
			free_lst(head);
			return (NULL);
		}
	}
	if (fd > 0)
		close(fd);
	return (head);
}

static int	**process_map_data(char **map, t_config **input)
{
	int	**map_temp;

	map_temp = NULL;
	if (verify_map(map, input) == -1)
		print_error(INVALID_MAP);
	else
		map_temp = create_map(map, input);
	if (map_temp == NULL)
		free_input((*input));
	if (map)
		free_array(map);
	print_map(*input, map_temp);
	return (map_temp);
}

static void	free_lst(t_lst *map_line)
{
	t_lst	*aux;

	if (!map_line)
		return ;
	while (map_line->next)
	{
		aux = map_line;
		map_line = map_line->next;
		free(aux->content);
		free(aux);
	}
	free(map_line->content);
	free(map_line);
}

static char	**lst_to_arr(t_lst *lst)
{
	int		i;
	int		size;
	t_lst	*head;
	char	**map;

	i = 0;
	size = 0;
	head = NULL;
	map = NULL;
	if (!lst)
		return (NULL);
	head = lst;
	size = ft_lstsize(head);
	map = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		map[i] = ft_strdup(head->content);
		head = head->next;
		i++;
	}
	free_lst(lst);
	return (map);
}

int	**read_map(int fd, t_config **input)
{
	t_lst	*new;
	int		**map;
	char	**map_temp;

	new = malloc(sizeof(t_lst));
	new->content = NULL;
	new->next = NULL;
	map_temp = lst_to_arr(remove_empty(read_map_lines(fd, new)));
	map = process_map_data(map_temp, input);
	return (map);
}
