/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 21:00:41 by yelee             #+#    #+#             */
/*   Updated: 2019/12/30 18:16:21 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		num_count(unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	return (i + 1);
}

char					*ft_itoa(int n)
{
	char				*str;
	unsigned int		len;
	unsigned int		i;
	unsigned int		nbr;

	nbr = (unsigned int)n;
	if (n < 0)
		nbr = nbr * (-1);
	i = 0;
	len = num_count(nbr);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (str[i] = '-'))
		len++;
	i = len - 1;
	while (nbr >= 10)
	{
		str[i--] = (char)(nbr % 10 + 48);
		nbr = nbr / 10;
	}
	str[i] = (char)(nbr % 10 + 48);
	str[len] = '\0';
	return (str);
}
