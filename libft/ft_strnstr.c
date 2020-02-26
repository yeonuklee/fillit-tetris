/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:57:58 by yelee             #+#    #+#             */
/*   Updated: 2019/12/17 13:31:54 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)&s1[i]);
	while (s1[i] && i < len)
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			temp = (char *)(s1 + i);
			while (s1[i] == s2[j] && i < len)
			{
				++i;
				++j;
				if (s2[j] == '\0')
					return (temp);
			}
		}
		++i;
	}
	return (NULL);
}
