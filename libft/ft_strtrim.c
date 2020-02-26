/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 10:55:37 by yelee             #+#    #+#             */
/*   Updated: 2019/12/31 13:50:19 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!*s)
		return (str = ft_strnew(len));
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' ||
				s[len - 1] == '\t') && s[i] != '\0')
		len--;
	if (!(str = ft_strsub(s, i, (size_t)(len - i))))
		return (NULL);
	return (str);
}
