/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 21:14:31 by yelee             #+#    #+#             */
/*   Updated: 2019/12/26 21:14:36 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srclen;

	i = ft_strlen(dst);
	srclen = ft_strlen(src);
	j = 0;
	if (dstsize == 0)
		return (srclen);
	if (dstsize < i)
		srclen += dstsize;
	else
		srclen += i;
	while (src[j] != '\0' && i < dstsize - 1 && dst != src)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
