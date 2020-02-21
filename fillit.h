#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define SIZE 21
#define ARRAY_SIZE 26
#define MAX_SIZE 1024

#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

typedef struct  s_tetris
{  
    char                    *tetriminos;
    int                     height;
    int                     width;
    int                     coord[8];
    struct      s_tetris    *next;
    
}                           t_tetris;

typedef struct	s_board
{
	int						**board;
	int						height;
	int						width;
}				t_board;

char		*ft_map(int size);
int			ft_smallest_size(int size);
void		ft_recoordi(t_tetris **head);
void		ft_coordination(t_tetris **head);
int         ft_valid2(t_tetris **head);
int         ft_valid1(t_tetris **head);
int         ft_errorcheck(t_tetris **head);
int			ft_size(t_tetris **head);
void        ft_addtoend(t_tetris **head, t_tetris *new);
t_tetris	**ft_getfile(int fd, char *filename, t_tetris **head);
t_tetris    *ft_newnode(char *str);
void        ft_fillit2(int fd, char *str);
int         main(int ac, char **av);

#endif