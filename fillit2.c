#include "fillit.h"

// void		ft_printmap(char *new_map, t_tetris *head)
// {

// }

// int			ft_backtrack(char *new_map, t_tetris *head)
// {
	
// }

// void		ft_solver(int size, t_tetris *head)
// {
// 	char	*new_map;
// 	int		i;

// 	i = 0;
// 	while (i == 0)
// 	{
// 		new_map = ft_map(size);
// 		i = ft_backtrack();
// 		if (i == 1)
// 		{
// 			ft_printmap()
// 			free(new_map);
// 		}
// 		else
// 		{
// 			free(new_map);
// 			size++;
// 		}
// 	}
// }

char		*ft_map(int size)
{
	char	*map;
	int		i;
	int		x;

	i = 0;
	x = ft_smallest_size(size);
	x = (x + 1) * x;
	if(!(map = ft_strnew(size))) //square size + 1 for null
		return (NULL);
	//ft_memset(map, '.', size * sizeof(char));
	while (i < size)
	{
		if (size % i == 0)
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	map[i] = '\0';
	return (map);
}

int			ft_smallest_size(int size)
{
	//size is the number of structure
	int		total_blocks;
	int		i;

	total_blocks = size * 4; //the total number of tetriminos
	i = 0;
	while (i * i < total_blocks)
		i++;
	return (i);
}

void		ft_recoordi(t_tetris **head)
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
			if (temp->tetriminos[i] == '#')
			{
				while (j < 8)
				{
					temp->coord[j] = temp->coord[j] - (i % 5);
					j++;
					temp->coord[j] = temp->coord[j] - (i / 5);
					j++;
				}
			}
			i++;
		}
		temp = temp->next;
	}
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
			if (temp->tetriminos[i] == '#')
			{
				temp->coord[j] = i % 5; // coordi of row is 0/2/4..
				temp->coord[++j] = i / 5; //coordi of col is 1/3/5..
			}
			i++;
		}
		temp = temp->next;
	}
	ft_recoordi(head);
}

int		ft_valid2(t_tetris **head)
{
	int			i;
	int			j;
	int			count;
	t_tetris	*temp;
	
	temp = *head;
	while (temp->next)
	{
		i = 0;
		count = 0;
		while (i < 21)
		{
			if ((i % 5 == 4 && temp->tetriminos[i] != '\n') || (i == 20 && temp->tetriminos[i] != '\n')) //to check if it's 4x4
				count++;
			if ((i % 5 != 4 && i != 20) && (temp->tetriminos[i] != '.' && temp->tetriminos[i] != '#'))  // check the character either # or .
				count++;
			count > 0 ? ft_putstr("3 error"), exit(0) : count;
			i++;
		}
		j = 0;
		temp = temp->next;
	}
	return (1);
}

int		ft_valid1(t_tetris **head)
{
	t_tetris	*temp;
	int			i;
	int			count;

	temp = *head;
	while (temp->next)
	{
		count = 0;
		i = 0;
		while (i < SIZE) //SIZE is the size of array in the structure. 
		{
			if (temp->tetriminos[i] == '#')
			{
				(i < 16 && temp->tetriminos[i + 5] == '#') ? count++ : count;
				(i > 4 && temp->tetriminos[i - 5] == '#') ? count++ : count;
				(i != 0 && temp->tetriminos[i - 1] =='#') ? count++ : count;
				(temp->tetriminos[i - 1] == '#') ? count++ : count;
			}
			i++;
		}
		(count != 6 && count != 8) ? ft_putstr("error"), exit(0) : count; //if it's not valid shape, just terminate programe.
		temp = temp->next;
	}
	return (1);
}

int			ft_errorcheck(t_tetris **head)
{
	t_tetris	*temp;
	int			count;
	int			i;

	temp = *head;
	while (temp->next)
	{
		count = 0;
		i = 0;
		while (i < SIZE)
		{
			if (temp->tetriminos[i] == '\n')
				count++;
			count > 5 ? ft_putstr("1 error\n"), exit(0) : count;
			i++;
		}
		temp = temp->next;
	}
	// if (ft_valid1(&head) == 0 && ft_valid2(&head) == 0)
	// {	
	// 	ft_putstr("error\n");
	// 	exit(0);
	// }
	// ft_valid1(size, str) == 1 ? printf("\nvalid 1 ok\n") : printf("\nv1 error\n");
	// ft_valid2(size, str) == 1 ? printf("\nvalid 2 ok\n") : printf("\nv2 error\n");
	return (1);
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
	if (count > 26) // if there are more than 26 tet, error
	{
		ft_putstr("error\n");
		exit(0);
	}
	return (count);
}

void	ft_addtoend(t_tetris **head, t_tetris *new)
{
	t_tetris	*temp;

	temp = *head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}

t_tetris	**ft_getfile(int fd, char *filename, t_tetris **head)
{
	//t_tetris	*head;
	t_tetris	*t_tet;
	char		*str;
	int			i;

	i = 1;
	*head = NULL;
	if (!(str = (char*)malloc(sizeof(char) * SIZE)) || read(fd, str, 0) < 0)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, str, SIZE);
		str[i] = '\0';
		t_tet = ft_newnode(str);
		ft_addtoend(head, t_tet);
		if (str[i - 1] != '\0')
			t_tet->tetriminos = ft_strdup(str);
		else
			t_tet->tetriminos = ft_strsub(str, 0, SIZE - 1);
	}
	free(str);
	close(fd);
	return (head);
}

t_tetris    *ft_newnode(char *str)
{
	t_tetris	*t_tet;
	
	if (!(t_tet = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!str)
		t_tet->tetriminos = NULL;
	else
		t_tet->tetriminos = ft_strdup(str); // allocate the memory?
	t_tet->next = NULL;
	return (t_tet);
}

t_board ft_initboard(int row, int col)
{
	t_board board;
//	board.board[row][col];
	board.height = row;
	board.width = col; //maybe not -1 for \n
	board.board = ft_memalloc(sizeof(int[row][col]));
	int rrow; //x = row, y = col
	int ccol;
	
	rrow = 0;
	ccol = 0;
	while (ccol < col)
	{
		rrow = 0;
		while (rrow < row - 1)
		{
			board.board[rrow][ccol] = '.';
			rrow++;
		}
//		board.board[rrow][ccol] = '\n';
		ccol++;
	}
	return board;
}
//taking a single cord.
int ft_veri(t_board board, int row, int col, t_tetris coords)
{
	int count;
	count = 0;
	//@todo optimize to disregard height and width of the tet
	if (coords.height + row < board.height && coords.width + col < board.width)
	{
		while(count < 4)
		{ //maybe segfaults here
			if(board.board[row + coords.coord[count]][col + coords.coord[count*2]] == '.')
			{
				count++;
			}
			else 
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}
void ft_printboard(t_board board)
{
	int row;
	int col;
	int i = 0;
	
	row = 0; 
	col = 0;
	while (row < board.height)
	{
		row = 0;
		while (col < board.width)
		{
			board.board[row][col] = 65 + i; 
			ft_putchar(board.board[row][col]);
			row++;
		}
		ft_putchar('\n');
		col++;
		i++;
	}
}
void ft_place(t_board board, int row, int col, t_tetris tet)
{
	int count;
	count = 0;
	while(count < 4)
	{
		board.board[row + tet.coord[count]][col + tet.coord[count*2]] = tet.tetriminos[0];
	}
}
//x, y is size of the starting board, tet_max how many tets working with
int	ft_track(t_tetris *coords, int row, int col, int tet_max)
{
	int rrow;
	int ccol;
	int tet; //which tet we're placing
	
	tet = 0;
	rrow = 0;
	ccol = 0;
	if (tet == tet_max)
	{
		return 1; //all placed, done!
	}
	t_board board;
	board = ft_initboard(row, col);
	while (tet <= tet_max)
	{
		//find empty spot
		//check box, if filled, && more pieces, make bigger box
		//place the tet & check for fitment
		if (rrow >= row) //check board == full, or is it  y <= yy. Figure that out later
		{
			return ft_track(coords, row+1, col+1, tet_max);
		}
		while (ccol < col)
		{
			rrow = 0;
			while (rrow < row)
			{
				if(ft_veri(board, rrow, ccol, coords[tet]))
				{
					ft_place(board, rrow, ccol, coords[tet]);
					//insert the thing on board
				}
				if(ft_track(coords, row, col, tet_max))
				{
					return 1; 	//if fits return true.
				}
				rrow++;
			}
			ccol++;
		}
	}
	return 0; // 0 == false, 1 == true.
}

void		ft_fillit2(int fd, char *str)
{
	t_tetris	**head;
	char		*map;
	int			size;
	int			error;

	if (!(head = (t_tetris**)malloc(sizeof(t_tetris*))))
		return ;
	head = ft_getfile(fd, str, head);
	size = ft_size(head);
	error = ft_errorcheck(head);
	ft_coordination(head);
	map = ft_map(size);
	ft_track(*head, 2, 2, size); // @todo optimize.


	

}

int main(int ac, char **av)
{
	int fd;

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) < 0 || fd > MAX_SIZE)
	{
		ft_putstr("error\n");
		return (1);
	}
	ft_fillit2(fd, av[1]);
	return (0);
}