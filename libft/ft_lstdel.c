/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 16:58:06 by yelee             #+#    #+#             */
/*   Updated: 2019/12/23 16:58:25 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;
	t_list *temp;

	ptr = *alst;
	while (ptr)
	{
		temp = ptr;
		ft_lstdelone(&ptr, del);
		ptr = temp->next;
	}
	*alst = NULL;
}
