/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddtoend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:56:43 by yelee             #+#    #+#             */
/*   Updated: 2020/02/25 15:04:27 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddtoend(t_list **alst, t_list *new)
{
	t_list	*temp;

	temp = *alst;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}
