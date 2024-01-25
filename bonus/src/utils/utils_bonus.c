/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:56:45 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 15:06:11 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
	line = NULL;
	if (!start || !start->content)
		return (NULL);
	while (start)
	{
		line = remove_whitespaces(start->content, 0);
		if (!line)
		{
			print_error(NO_MAP);
			break ;
		}
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

char	*remove_whitespaces(const char *str, int flag)
{
	char	*whitespaces;
	char	*trimmed;

	whitespaces = "\t\v\f\r\n ";
	trimmed = ft_strtrim(str, whitespaces);
	if (flag != 0)
		free((void *)str);
	return (trimmed);
}
