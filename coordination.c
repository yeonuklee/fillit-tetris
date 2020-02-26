/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:38:19 by yelee             #+#    #+#             */
/*   Updated: 2020/02/25 14:38:34 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_recoordi(t_tetris **head)
{
	t_tetris	*temp;
	int			i;
	int			j;
	int			k;

	temp = *head;
	k = -1;
	while (temp->next)
	{
		i = -1;
		j = 0;
		while (++i < SIZE)
			if (temp->tet[i] == '#')
				while (j < 8)
				{
					temp->coord[j] = temp->coord[j] - (i % 5);
					temp->coord[j + 1] = temp->coord[j + 1] - (i / 5);
					j += 2;
				}
		temp->tet[0] = ++k + 'A';
		temp = ft_updatetet(temp)->next;
	}
}

int			ft_smallest_size(int size)
{
	int		total_blocks;
	int		i;

	total_blocks = size * 4;
	i = 0;
	while (i * i < total_blocks)
		i++;
	return (i);
}

void		ft_coordination(t_tetris **head)
{
	t_tetris	*temp;
	int			i;
	int			j;

	temp = *head;
	while (temp->next)
	{
		i = 0;
		j = 0;
		while (i < SIZE)
		{
			if (temp->tet[i] == '#')
			{
				temp->coord[j] = i % 5;
				j++;
				temp->coord[j] = i / 5;
				j++;
			}
			i++;
		}
		temp = temp->next;
	}
	ft_recoordi(head);
}
