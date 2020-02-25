/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyeung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:09:29 by tyeung            #+#    #+#             */
/*   Updated: 2020/02/25 15:09:32 by tyeung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_board	*ft_backtrack(t_tetris *coords, t_board *board, int row)
{
	int			col;
	t_tetris	*tet;

	if (!coords->next)
	{
		board->found = 1;
		return (board);
	}
	tet = coords;
	while (++row < board->len)
	{
		col = -1;
		while (++col < board->len)
			if (ft_check(board, col, row, *tet) == 1)
			{
				if (ft_backtrack(tet->next, board, -1)->found == 1)
					return (board);
				else
					ft_remove(board, *tet);
			}
	}
	return (board);
}

int		ft_check(t_board *board, int col, int row, t_tetris tet)
{
	int i;

	i = 0;
	if (col + tet.negw < 0)
		return (0);
	if ((tet.width + col > board->len) || (tet.height + row > board->len))
		return (0);
	while (i < 8)
	{
		if (board->board[col + tet.coord[i]][row + tet.coord[i + 1]] == '.')
			i += 2;
		else
			return (0);
	}
	ft_insert(board, col, row, tet);
	return (1);
}

void	ft_insert(t_board *board, int col, int row, t_tetris tet)
{
	board->board[col + tet.coord[0]][row + tet.coord[1]] = tet.tet[0];
	board->board[col + tet.coord[2]][row + tet.coord[3]] = tet.tet[0];
	board->board[col + tet.coord[4]][row + tet.coord[5]] = tet.tet[0];
	board->board[col + tet.coord[6]][row + tet.coord[7]] = tet.tet[0];
	tet.tet[2] = col;
	tet.tet[3] = row;
}

void	ft_remove(t_board *board, t_tetris tet)
{
	board->board[tet.tet[2] + tet.coord[0]][tet.tet[3] + tet.coord[1]] = '.';
	board->board[tet.tet[2] + tet.coord[2]][tet.tet[3] + tet.coord[3]] = '.';
	board->board[tet.tet[2] + tet.coord[4]][tet.tet[3] + tet.coord[5]] = '.';
	board->board[tet.tet[2] + tet.coord[6]][tet.tet[3] + tet.coord[7]] = '.';
}
