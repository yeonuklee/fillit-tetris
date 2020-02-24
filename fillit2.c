#include "fillit.h"

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

	row = 0;
	if(board->board != NULL)
	{
		col = board->len - 1;
		while(col >= 0)
		{
			free(board->board[col--]);
		}
		free(board->board);
		board->board = NULL;
	}
	board->len = len;
	board->board = (int**)malloc(len * sizeof(int*));
	while (row < len)
	{
		col = 0;
		board->board[row] = (int*)malloc(len * sizeof(int));
		while(col < len)
		{
			board->board[row][col] = '.';
			++col;
		}
		++row;
	}
	return board;
}

int ft_check(t_board *board, int col, int row, t_tetris tet)
{
	int i;

	i = 0;
	if((col == 0) && (tet.negw < 0))
		return 0;
 	if ((tet.width + col > board->len) || (tet.height + row > board->len))
		return 0;
	while(i < 8)
	{ 
		if(board->board[col + tet.coord[i]][row + tet.coord[i + 1]] == '.')
			i += 2;
		else 
			return 0;
	}
	return 1;
}

t_board *ft_insert(t_board *board, int col, int row, t_tetris tet)
{
	int count;
	
	count = 0;
	while(count <= 6)
	{
		board->board[col + tet.coord[count]][row + tet.coord[count+1]] = tet.tetriminos[0];
		count += 2;
	}
	return (board);
}

t_board *ft_rmpiece(t_board *board, t_tetris tet)
{
	int	row;
	int	col;
	int count;

	row = 0;
	count = 0;
	while(row < board->len)
	{
		col = 0;
		while(col < board->len)
		{
			if(board->board[col][row] == tet.tetriminos[0])
			{
				board->board[col][row] = '.';
				++count;
			}
			if (count == 4)
			{
				return (board);
			}
			++col;
		}
		++row;
	}
	return (board);
}

t_board	*ft_backtrack(t_tetris *coords, t_board *board, int size)
{
	int			row;
	int			col;
	t_tetris	*tet;
	t_board 	temp;

	if (!coords->next)
	{
		board->found = 1;
		return (board);
	}
	tet = coords;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if(ft_check(board, col, row, *tet) == 1)
			{
//				temp = *board;
				ft_insert(board, col, row, *tet);
//				if (ft_backtrack(tet->next, &temp, size)->found == 1)
				if (ft_backtrack(tet->next, board, size)->found == 1)
				{
					
					return(board);
				}
				else
				{
					ft_rmpiece(board, *tet);
				}
				
			}
			++col;
		}
		++row;
	}
	return (board); // 0 == false, 1 == true.
}

void		ft_recoordi(t_tetris **head)
{
	t_tetris	*temp;
	int			i;
	int			j;
	int			k;

	temp = *head;
	k = 0;
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
					++j;
					temp->coord[j] = temp->coord[j] - (i / 5);
					++j;
				}
			}
			i++;
		}
		ft_updatetet(temp);
		temp->tetriminos[0] = k + 'A';
		++k;
		temp = temp->next;
	}
}


void ft_updatetet(t_tetris *tet)
{
	int	i;

	tet->height = 0;
	tet->width = 0;
	i = 0;
	tet->negw = 0;
	while(i < 8)
	{
		if(tet->width < tet->coord[i])
			tet->width = tet->coord[i];
		if(tet->coord[i] == -1 && !tet->negw)
			--(tet->negw);
		++i;
		if(tet->height < tet->coord[i])
			tet->height = tet->coord[i];
		++i;
	}
	tet->height += 1;
	tet->width += 1 + (tet->negw * -1);
}



void		free_structure(t_tetris *head)
{
	t_tetris	*list;

	while (head->next)
	{
		list = head->next;
		if (head->tetriminos)
			free(head->tetriminos);
		free(head);
		head = list;
	}
}

int			ft_smallest_size(int size)
{
	int		total_blocks;
	int		i;

	total_blocks = size * 4; //the total number of tetriminos
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
			if (temp->tetriminos[i] == '#')
			{
				temp->coord[j] = i % 5;; // coordi of row is 0/2/4..
				j++;
				temp->coord[j] = i / 5; //coordi of col is 1/3/5..
				j++;
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
		//printf("\n\ncount: %d\n\n", count);
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
	if (ft_valid1(head) != 1 && ft_valid2(head) != 1)
	{	
		ft_putstr("error\n");
		exit(0);
	}
	// ft_valid1(head) == 1 ? printf("\nvalid 1 ok\n") : printf("\nv1 error\n");
	// ft_valid2(head) == 1 ? printf("\nvalid 2 ok\n") : printf("\nv2 error\n");
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
	if(!(*head))
		*head = new;
	else
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		(temp)->next = new;
	}
}

t_tetris	**ft_getfile(int fd, t_tetris **head)
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
		if (str[i - 1] != '\0')
			t_tet->tetriminos = ft_strdup(str);
		else
			t_tet->tetriminos = ft_strsub(str, 0, SIZE - 1);
		ft_addtoend(head, t_tet);
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

void		ft_fillit2(int fd)
{
	t_tetris	**head;
	int			size;
	int			error;

	t_board *board;
	board = (t_board*)malloc(sizeof(t_board*));
	board->board = NULL;
	if (!(head = (t_tetris**)malloc(sizeof(t_tetris*))))
		return ;
	head = ft_getfile(fd, head);
	error = ft_errorcheck(head);
	printf("error: %d\n", error);
	ft_coordination(head);
	size = ft_smallest_size(ft_size(head));
	board->found = 0;
	while(board->found == 0)
	{
		ft_initboard(board, size);
/* 		printf("d0. %d.%d\n", (*head)->coord[0], (*head)->coord[1]);
		printf("d0. %d.%d\n", (*head)->coord[2], (*head)->coord[3]);
		printf("d0. %d.%d\n", (*head)->coord[4], (*head)->coord[5]);
		printf("d0. %d.%d\n", (*head)->coord[6], (*head)->coord[7]);
 */		ft_backtrack(*head, board, size);
		++size;
	}
	printboard(board);
	free_structure(*head);
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
	ft_fillit2(fd);
	return (0);
}