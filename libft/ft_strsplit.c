/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:51:32 by yelee             #+#    #+#             */
/*   Updated: 2019/12/31 14:51:46 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		size_count(char const *s, char c)
{
	size_t			count;

	count = 0;
	while (*s)
	{
		while (*s != c && *s)
		{
			s++;
			if (*s == c)
				count++;
		}
		s++;
	}
	return (count);
}

static size_t		word_count(char const *s, char c)
{
	size_t			count;

	count = 0;
	while (*s != c && *s)
	{
		count++;
		s++;
	}
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = (char**)ft_memalloc(sizeof(char*) * (size_count(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		j = 0;
		if (*s != c)
		{
			if (!(str[i] = ft_strnew(word_count(s, c))))
				return (NULL);
			while (*s && *s != c)
				str[i][j++] = *(s++);
			i++;
		}
		else
			s++;
	}
	return (str);
}
