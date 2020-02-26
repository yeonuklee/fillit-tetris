/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:56:59 by yelee             #+#    #+#             */
/*   Updated: 2019/12/17 13:23:14 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	size_t	len;
	size_t	i;

	if (!s || !*s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(ptr = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		ptr[i] = f(s[i]);
		i++;
	}
	return (ptr);
}
