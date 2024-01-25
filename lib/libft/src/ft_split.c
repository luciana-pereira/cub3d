/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:25:10 by lucperei          #+#    #+#             */
/*   Updated: 2024/01/25 15:20:56 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*s && *s == c)
	{
		s++;
	}
	while (s[i])
	{
		if (!i)
		{
			count++;
		}
		else if (s[i - 1] == c && s[i] != c)
		{
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	end;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_count_word(s, c);
	str = (char **)malloc(sizeof(char *) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	end = 0;
	while (i < size)
	{
		while (*s && *s == c)
			s++;
		end = ft_len(s, c);
		str[i] = ft_substr(s, 0, end);
		s += end + 1;
		i++;
	}
	str[size] = NULL;
	return (str);
}
