/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:38:47 by yelee             #+#    #+#             */
/*   Updated: 2020/02/25 14:39:24 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_exit(void)
{
	ft_putstr("error\n");
	exit(0);
}

void		ft_valid2(t_tetris **head, int size)
{
	int			i;
	int			j;
	int			count;
	t_tetris	*temp;

	temp = *head;
	j = 1;
	while (temp->next)
	{
		i = 0;
		count = 0;
		while (i < 21)
		{
			(i % 5 == 4 && temp->tet[i] != '\n') ||
			(i == 20 && temp->tet[i] != '\n') ? count++ : count;
			(i == 20 && temp->tet[i] != '\n') && j == size ? count = 0 : count;
			j == size && temp->tet[20] != '\0' ? count++ : count;
			(i % 5 != 4 && i != 20) &&
			(temp->tet[i] != '.' && temp->tet[i] != '#') ? count++ : count;
			count > 0 ? ft_exit() : count;
			i++;
		}
		j++;
		temp = temp->next;
	}
}

void		ft_valid1(t_tetris **head, int size)
{
	t_tetris	*temp;
	int			i;
	int			c;
	int			j;

	j = 1;
	temp = *head;
	while (temp->next)
	{
		c = 0;
		i = -1;
		while (++i < SIZE)
			if (temp->tet[i] == '#')
			{
				(j != size && i < 16 && temp->tet[i + 5] == '#') ? c++ : c;
				(j == size && i < 15 && temp->tet[i + 5] == '#') ? c++ : c;
				(i > 4 && temp->tet[i - 5] == '#') ? c++ : c;
				(i != 0 && temp->tet[i - 1] == '#') ? c++ : c;
				(i != 20 && temp->tet[i + 1] == '#') ? c++ : c;
			}
		(c != 6 && c != 8) ? ft_exit() : c;
		temp = temp->next;
		j++;
	}
}

void		ft_errorcheck(t_tetris **head, int size)
{
	t_tetris	*temp;
	int			count;
	int			i;

	temp = *head;
	count = 0;
	while (temp->next)
	{
		count = 0;
		i = 0;
		while (i < SIZE)
		{
			if (temp->tet[i] == '\n')
				count++;
			count > 5 ? ft_exit() : count;
			i++;
		}
		temp = temp->next;
	}
	count == 0 ? ft_exit() : count;
	ft_valid2(head, size);
	ft_valid1(head, size);
}

int			ft_size(t_tetris **head)
{
	t_tetris	*temp;
	int			count;

	count = 0;
	temp = *head;
	while (temp->next)
	{
		count++;
		temp = temp->next;
	}
	if (count > 26)
	{
		ft_putstr("error\n");
		exit(0);
	}
	return (count);
}
