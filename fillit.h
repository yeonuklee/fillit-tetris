#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define SIZE 21
#define ARRAY_SIZE 26
#define MAX_SIZE 1024

#include "libft/srcs/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct              s_tetris
{  

    char                    *tetriminos;
    int                     height;
    int                     width;
    int                     negw;
    int                     coord[8];
    struct      s_tetris    *next;
}                           t_tetris;

typedef struct	s_board
{
	int						**board;
	int						len;
    int                     found;
}               t_board;


void        ft_updatetet(t_tetris *tet);
void		ft_recoordi(t_tetris **head);
t_board     *ft_backtrack(t_tetris *coords, t_board *board, int size);

t_board     *ft_insert(t_board *board, int row, int col, t_tetris tet);
int         ft_check(t_board *board, int row, int col, t_tetris coords);
//t_board     *ft_initboard(t_board *board, int len);
//void        printboard(t_board *board);
//char		*ft_map(int size);
void        free_structure(t_tetris *head);
int			ft_smallest_size(int size);
void		ft_recoordi(t_tetris **head);
void		ft_coordination(t_tetris **head);
int         ft_valid2(t_tetris **head);
int         ft_valid1(t_tetris **head);
int         ft_errorcheck(t_tetris **head);
int			ft_size(t_tetris **head);
void        ft_addtoend(t_tetris **head, t_tetris *new);
t_tetris	**ft_getfile(int fd, t_tetris **head);
t_tetris    *ft_newnode(char *str);
void        ft_fillit2(int fd);
int         main(int ac, char **av);

#endif