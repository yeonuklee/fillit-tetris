/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 20:37:20 by yelee             #+#    #+#             */
/*   Updated: 2019/12/26 21:44:47 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ndst;
	const unsigned char	*nsrc;

	ndst = (unsigned char*)dst;
	nsrc = (const unsigned char*)src;
	i = 0;
	if (ndst > nsrc)
	{
		while (len--)
			ndst[len] = nsrc[len];
	}
	else
		ft_memcpy(ndst, nsrc, len);
	return (ndst);
}
