/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:29:31 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/04 17:29:24 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	list_clear(t_lst *lst)
{
	t_lst	*current;
	t_lst	*next_node;

	next_node = lst;
	while (next_node)
	{
		free(next_node->content);
		current = next_node;
		next_node = next_node->next;
		free(current);
	}
}

int	list_size(t_lst *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count - 1);
}

t_lst	*create_new_node(void)
{
	t_lst	*node;

	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->next = NULL;
	return (node);
}
