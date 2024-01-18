/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:21:16 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/18 01:57:05 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_numeric(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
		str++;
	return (!*str);
}

void	free_and_print_error(t_lst *start)
{
	free(start->content);
	free(start);
	print_error(NO_MAP);
}

t_lst	*remove_empty(t_lst *start)
{
	t_lst	*temp;
	char	*line;

	temp = start;
	while (start)
	{
		line = remove_whitespaces(start->content);
		if (!line)
			free_and_print_error(start);
		if (line[0] != 0)
			break ;
		temp = start->next;
		free(start->content);
		free(start);
		start = temp;
		free(line);
	}
	free(line);
	return (start);
}

char	*remove_whitespaces(const char *str)
{
	char	*whitespaces;
	char	*trimmed;

	whitespaces = "\t\v\f\r\n ";
	trimmed = ft_strtrim(str, whitespaces);
	return (trimmed);
}
