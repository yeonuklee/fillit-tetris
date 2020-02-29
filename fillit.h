/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:41:56 by yelee             #+#    #+#             */
/*   Updated: 2020/02/25 14:55:43 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define SIZE 21
# define MAX_SIZE 1024

# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_tetris
{

	char			*tet;
	int				height;
	int				width;
	int				negw;
	int				coord[8];
	struct s_tetris	*next;
}					t_tetris;

typedef struct		s_board
{
	int				**board;
	int				len;
	int				found;
}					t_board;

void				ft_freeboard(t_board *board);
t_tetris			*ft_updatetet(t_tetris *tet);
void				ft_recoordi(t_tetris **head);
t_board				*ft_backtrack(t_tetris *coords, t_board *board, int row);
void				printboard(t_board *board);
void				ft_remove(t_board *board, t_tetris tet);
void				ft_insert(t_board *board, int row, int col, t_tetris tet);
t_board				*ft_initboard(t_board *board, int len);
int					ft_check(t_board *board, int row, int col, t_tetris coords);
void				free_structure(t_tetris *head);
int					ft_smallest_size(int size);
void				ft_coordination(t_tetris **head);
void				ft_valid2(t_tetris **head, int size);
void				ft_valid1(t_tetris **head, int size);
void				ft_valid3(t_tetris **head);
void				ft_errorcheck(t_tetris **head, int size);
int					ft_size(t_tetris **head);
void				ft_addtoend(t_tetris **head, t_tetris *new);
t_tetris			**ft_getfile(int fd, t_tetris **head);
t_tetris			*ft_newnode(char *str);
void				ft_fillit2(int fd);
int					main(int ac, char **av);
void				ft_exit(void);

#endif
