#include "fillit.h"

t_tetris	*ft_updatetet(t_tetris *tet)
{
	int	i;

	tet->height = 0;
	tet->width = 0;
	tet->negw = 0;
	i = -1;
	while(++i < 8)
	{
		if(tet->width < tet->coord[i])
			tet->width = tet->coord[i];
		else if(tet->negw > tet->coord[i])
			tet->negw = tet->coord[i];
		if(tet->height < tet->coord[++i])
			tet->height = tet->coord[i];
	}
	tet->height += 1;
	tet->width += 1;
	return (tet);
}

void printboard(t_board *board)
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
}

t_board *ft_initboard(t_board *board, int len)
{
	int row;
	int col;

	row = -1;
	if(board->board != NULL)
	{
		col = board->len;
		while(--col >= 0)
			free(board->board[col]);
		free(board->board);
		board->board = NULL;
	}
	board->len = len;
	board->board = (int**)malloc(len * sizeof(int*));
	while (++row < len)
	{
		col = -1;
		board->board[row] = (int*)malloc(len * sizeof(int));
		while(++col < len)
			board->board[row][col] = '.';
	}
	return (board);
}

int ft_check(t_board *board, int col, int row, t_tetris tet)
{
	int i;

	i = 0;
	if((col + tet.negw < 0))
		return (0);
 	if ((tet.width + col > board->len) || (tet.height + row > board->len))
		return (0);
	while(i < 8)
	{
		if(board->board[col + tet.coord[i]][row + tet.coord[i + 1]] == '.')
			i += 2;
		else
			return (0);
	}
	ft_insert(board, col, row, tet);
	return (1);
}

void	ft_insert(t_board *board, int col, int row, t_tetris tet)
{
	board->board[col + tet.coord[0]][row + tet.coord[1]] = tet.tetriminos[0];
	board->board[col + tet.coord[2]][row + tet.coord[3]] = tet.tetriminos[0];
	board->board[col + tet.coord[4]][row + tet.coord[5]] = tet.tetriminos[0];
	board->board[col + tet.coord[6]][row + tet.coord[7]] = tet.tetriminos[0];
	tet.tetriminos[2] = col;
	tet.tetriminos[3] = row;
}

void	ft_remove(t_board *board, t_tetris tet)
{
	board->board[tet.tetriminos[2] + tet.coord[0]][tet.tetriminos[3] + tet.coord[1]] = '.';
	board->board[tet.tetriminos[2] + tet.coord[2]][tet.tetriminos[3] + tet.coord[3]] = '.';
	board->board[tet.tetriminos[2] + tet.coord[4]][tet.tetriminos[3] + tet.coord[5]] = '.';
	board->board[tet.tetriminos[2] + tet.coord[6]][tet.tetriminos[3] + tet.coord[7]] = '.';
}

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
			if(ft_check(board, col, row, *tet) == 1)
			{
				if (ft_backtrack(tet->next, board, -1)->found == 1)
					return(board);
				else
					ft_remove(board, *tet);
			}
	}
	return (board);
}
