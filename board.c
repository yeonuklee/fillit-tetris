/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:09:40 by tyeung            #+#    #+#             */
/*   Updated: 2020/02/25 15:09:41 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_freeboard(t_board *board)
{
	int i;

	if (board->board != NULL)
	{
		i = board->len;
		while (--i >= 0)
			free(board->board[i]);
		free(board->board);
		board->board = NULL;
	}
}

t_tetris	*ft_updatetet(t_tetris *tet)
{
	int	i;

	tet->height = 0;
	tet->width = 0;
	tet->negw = 0;
	i = -1;
	while (++i < 8)
	{
		if (tet->width < tet->coord[i])
			tet->width = tet->coord[i];
		else if (tet->negw > tet->coord[i])
			tet->negw = tet->coord[i];
		if (tet->height < tet->coord[++i])
			tet->height = tet->coord[i];
	}
	tet->height += 1;
	tet->width += 1;
	return (tet);
}

t_board		*ft_initboard(t_board *board, int len)
{
	int row;
	int col;

	row = -1;
	ft_freeboard(board);
	board->len = len;
	board->board = (int**)malloc(len * sizeof(int*));
	while (++row < len)
	{
		col = -1;
		board->board[row] = (int*)malloc(len * sizeof(int));
		while (++col < len)
			board->board[row][col] = '.';
	}
	return (board);
}

void		printboard(t_board *board)
{
	int row;
	int col;

	row = 0;
	while (row < board->len)
	{
		col = 0;
		while (col < board->len)
		{
			ft_putchar(board->board[col][row]);
			++col;
		}
		ft_putchar('\n');
		++row;
	}
	ft_freeboard(board);
}
