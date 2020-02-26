/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 00:22:13 by yelee             #+#    #+#             */
/*   Updated: 2019/12/26 21:39:45 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*ndst;
	const unsigned char	*nsrc;
	size_t				i;

	ndst = (unsigned char*)dst;
	nsrc = (const unsigned char*)src;
	i = 0;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		ndst[i] = nsrc[i];
		i++;
	}
	return (ndst);
}
