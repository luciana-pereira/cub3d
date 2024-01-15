/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:33:32 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/07 23:02:59 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	count;
	size_t	index;

	count = 0;
	index = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	while (s1 && s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	while (s2 && s2[index])
	{
		str[count + index] = s2[index];
		index++;
	}
	str[count + index] = '\0';
	return (str);
}
