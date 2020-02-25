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
			if (temp->tetriminos[i] == '#')
				while (j < 8)
				{
					temp->coord[j] = temp->coord[j] - (i % 5);
					temp->coord[j+1] = temp->coord[j+1] - (i / 5);
					j += 2;
				}
		temp->tetriminos[0] = ++k + 'A';
		temp = ft_updatetet(temp)->next;
	}
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
			if (temp->tetriminos[i] == '#')
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

int		ft_valid2(t_tetris **head, int size)
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
			if ((i % 5 == 4 && temp->tetriminos[i] != '\n') || (i == 20 && temp->tetriminos[i] != '\n')) 
				count++;
			j == size ? count = 0 : count;
			j == size && temp->tetriminos[20] != '\0' ? count++ : count;
            count > 0 ? ft_putstr("error\n"), exit(0) : count;
			if ((i % 5 != 4 && i != 20) && (temp->tetriminos[i] != '.' && temp->tetriminos[i] != '#'))
				count++;
			count > 0 ? ft_putstr("error\n"), exit(0) : count;
			i++;
		}
		j++;
		temp = temp->next;
	}
	return (count);
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
		while (i < SIZE) 
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
		(count != 6 && count != 8) ? ft_putstr("error\n"), exit(0) : count; 
		temp = temp->next;
	}
	return (1);
}

int			ft_errorcheck(t_tetris **head, int size)
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
			count > 5 ? ft_putstr("error\n"), exit(0) : count;
			i++;
		}
		temp = temp->next;
	}
	if (ft_valid1(head) != 1 || ft_valid2(head,size) != 0)
	{	
		ft_putstr("error\n");
		exit(0);
	}
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
	if (count > 26)
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
	t_tetris	*t_tet;
	char		*str;
	int			i;

	*head = NULL;
	if (!(str = (char*)malloc(sizeof(char) * SIZE)) || read(fd, str, 0) < 0)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, str, SIZE);
		str[i] = '\0';
		t_tet = ft_newnode(str);
		t_tet->tetriminos = ft_strdup(str);
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
		t_tet->tetriminos = ft_strdup(str);
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
		return ; //error???
	head = ft_getfile(fd, head);
	size = ft_size(head);
	error = ft_errorcheck(head, size);
	ft_coordination(head);
	size = ft_smallest_size(size) - 1;
	board->found = 0;
	while(board->found == 0)
	{
		ft_initboard(board, ++size);
 		ft_backtrack(*head, board, -1);
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