#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define SIZE 21
#define ARRAY_SIZE 26
#define MAX_SIZE 1024

#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

int		ft_fillit(int fd, char *str);
char    **ft_getfile(int fd, char *str);
int		ft_getsize(char **str);
int		ft_errorcheck(int size, char **str);
int		ft_valid1(int size, char **str);
int		ft_valid2(int size, char **str);
char	**ft_rearrange(int size, char **str);

#endif