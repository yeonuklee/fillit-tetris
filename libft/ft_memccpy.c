/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 12:20:24 by yelee             #+#    #+#             */
/*   Updated: 2019/12/20 00:14:23 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ndst;
	unsigned const char	*nsrc;
	size_t				i;

	ndst = (unsigned char*)dst;
	nsrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ndst[i] = nsrc[i];
		if (ndst[i] == (unsigned char)c)
			return (void*)(dst + i + 1);
		i++;
	}
	return (NULL);
}
