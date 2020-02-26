/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:02:00 by yelee             #+#    #+#             */
/*   Updated: 2020/02/25 15:03:21 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_structure(t_tetris *head)
{
	t_tetris	*list;

	while (head->next)
	{
		list = head->next;
		if (head->tet)
			free(head->tet);
		free(head);
		head = list;
	}
	free(head->tet);
	free(head);
}
