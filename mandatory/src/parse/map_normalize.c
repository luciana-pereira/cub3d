/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:54:56 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/22 09:06:21 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int content_normalizer(char **content, int size)
{
	char	*temp;
	int		i;

	i = 0;
	temp = malloc((size + 1) * sizeof(char));
	if (!temp)
		return (-1);
	while ((*content)[i] != '\0')
	{
		temp[i] = (*content)[i];
		i++;
	}
	while (i < size)
	{
		temp[i] = ' ';
		i++;
	}
	temp[i] = '\0';
	free(*content);
	(*content) = temp;
	return (0);
}

int	map_normalizer(t_lst *map, t_config **input)
{
	t_lst *temp;

	temp = map;
	while (temp && temp->content)
	{
		process_map_line(temp->content, input);
		temp = temp->next;
	}
	temp = map;
	while (temp && temp->content)
	{
		if(ft_strlen(temp->content) != (*input)->width)
			if(content_normalizer(&temp->content, (*input)->width) == -1)
				return(-1);
		temp = temp->next;
	}
	return (0);
}

int	map_checker(t_lst *prev, t_lst *map, int size)
{
	int	i;

	i = 0;
	while (map->content[i] != '\0')
	{
		if((map->content[i] == '0' || ft_strchr("NSWE", map->content[i]))\
									&& (map == prev\
									|| map->next == NULL\
									|| i == 0\
									|| i == size\
									|| map->content[i + 1] == ' '\
									|| map->content[i - 1] == ' '\
									|| prev->content[i] == ' '\
									|| map->next->content[i] == ' '))
			return (-1);
		i++;
	}
	return(0);
}