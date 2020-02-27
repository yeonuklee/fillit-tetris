/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:39:39 by yelee             #+#    #+#             */
/*   Updated: 2020/02/25 15:55:54 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_fillit2(int fd)
{
	t_tetris	**head;
	int			size;
	t_board		*board;

	board = (t_board*)malloc(sizeof(t_board));
	board->board = NULL;
	if (!(head = (t_tetris**)malloc(sizeof(t_tetris*))))
		return ;
	head = ft_getfile(fd, head);
	size = ft_size(head);
	ft_errorcheck(head, size);
	ft_coordination(head);
	size = ft_smallest_size(size) - 1;
	board->found = 0;
	while (board->found == 0)
	{
		ft_initboard(board, ++size);
		ft_backtrack(*head, board, -1);
	}
	printboard(board);
	free_structure(*head);
	free(board);
	free(head);
}

int			main(int ac, char **av)
{
	int	fd;

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
