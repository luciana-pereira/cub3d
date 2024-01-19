/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:28:57 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/19 15:12:12 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	if (str[index] == '\0')
		return (0);
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	ft_lstsize(t_lst *lst)
{
	int		nodecount;
	t_lst	*temp;

	nodecount = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		nodecount++;
	}
	return (nodecount);
}


