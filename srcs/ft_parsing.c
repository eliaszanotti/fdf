/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:00:27 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 16:45:08 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*ft_get_atoi_tab(char **tab, t_grid *grid)
{
	int		*int_tab;
	ssize_t	i;

	i = 0;
	while (tab[i])
		i++;
	grid->cols = i;
	int_tab = ft_calloc(i + 1, sizeof(int));
	if (!int_tab)
		return (free(tab), NULL);
	i = -1;
	while (tab[++i])
	{
		int_tab[i] = ft_atoi(tab[i]);
		free(tab[i]);
	}	
	free(tab);
	return (int_tab);
}

int	**ft_get_int_tab(t_list *first)
{
	int	**int_tab;
	int	size;

	size = ft_lstsize(first);
	int_tab = ft_calloc(size + 1, sizeof(int *));
	size = 0;
	while (first)
	{
		int_tab[size++] = first->content;
		free(&first->content);
		first = first->next;
	}
	return (int_tab);
}

int	**ft_parsing(int fd, t_grid *grid)
{
	t_list	*first;
	t_list	*new;
	char	*line;
	char	**line_splited;
	int		*int_tab;

	first = NULL;
	line = get_next_line(fd);
	grid->lines = 0;
	grid->cols = 0;
	while (line)
	{
		grid->lines += 1;
		line_splited = ft_split(line, ' ');
		free(line);
		int_tab = ft_get_atoi_tab(line_splited, grid);
		new = ft_lstnew(int_tab);
		ft_lstadd_back(&first, new);
		line = get_next_line(fd);
	}
	return (ft_get_int_tab(first));
}
