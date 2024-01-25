/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:37:55 by luizedua          #+#    #+#             */
/*   Updated: 2024/01/25 13:59:07 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	close_fd(int fd)
{
	if (fd > 0)
		close(fd);
}

t_lst	*if_no_line(char *line, t_lst *head, t_lst *node)
{
	head = node;
	if (!line)
	{
		free(head);
		head = NULL;
	}
	return (head);
}

void	init_new(t_lst **newl)
{
	(*newl)->content = NULL;
	(*newl)->next = NULL;
}
