/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:53:20 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/07 22:54:53 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (c > 127)
	{
		c %= 256;
	}
	while (*s != c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}
