/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:33:11 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 15:08:49 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_lst	*read_map_lines(int fd, t_lst *node)
{
	char		*line;
	t_lst		*head;
	t_lst		*new;

	head = NULL;
	line = get_next_line(fd);
	head = if_no_line(line, head, node);
	while (line)
	{
		node->content = trim_end_space(line);
		new = (t_lst *)malloc(sizeof(t_lst));
		init_new(&new);
		node->next = new;
		node = node->next;
		if (check_line(line) >= 0)
			line = get_next_line(fd);
		else
		{
			close_fd(fd);
			free_lst(head);
			return (NULL);
		}
	}
	close_fd(fd);
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
	return (map_temp);
}

void	free_lst(t_lst *map_line)
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
	if (map_line)
	{
		free(map_line->content);
		free(map_line);
	}
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
	size = ft_lstsize(lst);
	map = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		map[i] = ft_strdup(lst->content);
		lst = lst->next;
		i++;
	}
	free_lst(head);
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
