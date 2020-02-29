/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:01:24 by yelee             #+#    #+#             */
/*   Updated: 2020/02/25 15:01:41 by yelee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_addtoend(t_tetris **head, t_tetris *new)
{
	t_tetris	*temp;

	temp = *head;
	if (!(*head))
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
	if (!(str = (char*)malloc(sizeof(char) * 22)) || read(fd, str, 0) < 0)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, str, SIZE);
		str[i] = '\0';
		t_tet = ft_newnode(str);
		ft_addtoend(head, t_tet);
	}
	free(str);
	close(fd);
	return (head);
}

t_tetris	*ft_newnode(char *str)
{
	t_tetris	*t_tet;

	if (!(t_tet = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	if (!str)
		t_tet->tet = NULL;
	else
		t_tet->tet = ft_strdup(str);
	t_tet->next = NULL;
	return (t_tet);
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
