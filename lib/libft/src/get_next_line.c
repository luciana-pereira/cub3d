/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:29:31 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 15:21:32 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Realizar novo ajuste na string para evitar estouro
static char	*create_combined_str(t_lst *list, size_t len)
{
	char	*str;
	size_t	index;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (list)
	{
		j = 0;
		while (list->content[j])
		{
			str[index + j] = list->content[j];
			j++;
		}
		index += j;
		list = list->next;
	}
	str[index] = '\0';
	return (str);
}

static char	read_line(int fd)
{
	size_t	bytes_read;
	char	current_char;

	current_char = 0;
	bytes_read = read(fd, &current_char, 1);
	if (bytes_read > 0)
	{
		return (current_char);
	}
	return (0);
}

static void	populate_list(int fd, t_lst *node)
{
	size_t	index;
	char	current_char;

	index = 0;
	current_char = 1;
	while (current_char)
	{
		node->content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		while (current_char && index < BUFFER_SIZE)
		{
			current_char = read_line(fd);
			node->content[index++] = current_char;
			if (current_char == '\n')
				break ;
		}
		node->content[index] = '\0';
		if (current_char == '\n')
			break ;
		if (current_char)
		{
			index = 0;
			node->next = create_new_node();
			node = node->next;
		}
	}
}

char	*get_next_line(int fd)
{
	char	*next_line;
	t_lst	*start;
	t_lst	*line;
	size_t	index;

	if (fd < 0)
		return (NULL);
	line = create_new_node();
	start = line;
	populate_list(fd, line);
	while (line->next)
		line = line->next;
	index = ft_strlen(line->content) + (BUFFER_SIZE * (list_size(start)));
	next_line = create_combined_str(start, index);
	list_clear(start);
	if (!next_line[0])
	{
		free (next_line);
		return (NULL);
	}
	return (next_line);
}
