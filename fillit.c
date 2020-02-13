#include "fillit.h"

char	**ft_rearrange(int size, char **str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < SIZE && str[i][j])
		{
			if (str[i][j] != '.' && str[i][j] != '\n')
				str[i][j] = 65 + i;
			j++;
		}
		printf("%s", str[i]);
		j = 0;
		i++;
	}
	return (str);
}

int		ft_valid2(int size, char **str)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (i < size)
	{
		while (j < 21)
		{
			if ((j % 5 == 4 && str[i][j] != '\n') || (j == 20 && str[i][j] != '\n')) //to check if it's 4x4
				count++;
			if ((j % 5 != 4 && j != 20) && (str[i][j] != '.' && str[i][j] != '#'))  // check the character either # or .
				count++;
			count > 0 ? write(1, "1 error\n", 6), exit(0) : count;
			j++;
		}
		j = 0;
		i++;
	}
	i > 26 ? write(1, "2 error", 6), exit(0) : count; // max 26 tetriminos 
	return (count);
}

int		ft_valid1(int size, char **str)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	while (i < size)
	{
		count = 0;
		while (j < 21)
		{
			if (str[i][j] == '#')
			{
				(j < 16 && str[i][j + 5] == '#') ? count++ : count;
				(j > 4 && str[i][j - 5] == '#') ? count++ : count;
				(j != 0 && str[i][j - 1] =='#') ? count++ : count;
				(str[i][j + 1] == '#') ? count++ : count;
			}
			j++;
		}
		(count != 6 && count != 8) ? write(1, "3 error\n", 6), exit(0) : count; //if it's not valid shape, just terminate programe.
		j = 0;
		i++;
	}
	return (count);
}

int		ft_errorcheck(int size, char **str)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	str[size - 1][20] = '\n';
	while (i < size) //check if there are only 6 \n or not. 
	{
		count = 0;
		while (j < 21)
		{
			if (str[i][j] == '\n')
				count++;
			count > 5 ? write(1, "4 error\n", 6), exit(0) : count;
			j++;
		}
		j = 0;
		i++;
	}
	if (ft_valid1(size, str) == 0 && ft_valid2(size, str) == 0)
		exit(0);
	ft_valid1(size, str) != 0 ? printf("\nvalid 1, valid\n") : printf("\nv1 error\n");
	ft_valid2(size, str) == 0 ? printf("\nvalid 2, valid\n") : printf("\nv2 error\n");
	str[size - 1][20] = '\0';
	return (1);
}

int		ft_getsize(int fd)
{
    int     i;
    int     count;
    char    c;

	i = 1;
    count = 0;
    while (i > 0)
    {
        i = read(fd, &c, 1);
        count++;
    }
    close(fd);
  //  printf("SIZE: %d\n", count/20);
	return (count / 20);
}

char			**ft_getfile(int fd, int size, char *filename)
{
	char	**line;
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 1;
	line = (char**)malloc(sizeof(char*) * size);
	str = (char*)malloc(sizeof(char) * SIZE);
	if ((fd = open(filename, O_RDONLY)) < 0 || !str || !line || read(fd, str, 0) < 0)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, str, SIZE);
		str[i] = '\0';
		if (str[i - 1] != '\0')
			line[j] = ft_strdup(str);
		else
			line[j] = ft_strsub(str, 0, SIZE - 1);
	//	printf("%s", line[j]);
		j++;
	}
//	printf("---------------------------------\n");
	free(str);
	close(fd);
	return (line);
}

int		ft_fillit(int fd, char *filename)
{
	char	**line;
	int		i;
	int		size;
	char	**line2;

	size = ft_getsize(fd);
	line = ft_getfile(fd, size, filename);
	i = ft_errorcheck(size, line);
//	line2 = ft_rearrange(size, line);
	
	return (0);
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
	ft_fillit(fd, av[1]);
	return (0);
}