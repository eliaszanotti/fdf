/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:00:27 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/25 18:42:00 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_get_atoi_tab(char **tab)
{
	int		*int_tab;
	ssize_t	i;

	i = 0;
	while (tab[i])
		i++;
	int_tab = ft_calloc(i + 1, sizeof(int));
	if (!int_tab)
		return (free(tab), NULL);
	i = -1;
	while (tab[++i])
		int_tab[i] = ft_atoi(tab[i]);
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
		first = first->next;
	}
	while (first)
	{
		free(first->content);
		first = first->next;
	}
	free(first);
	return (int_tab);
}

int	**ft_parsing(int fd)
{
	t_list	*first;
	t_list	*new;
	char	*line;
	int		*int_tab;

	first = NULL;
	line = ft_calloc(1, sizeof(char));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		int_tab = ft_get_atoi_tab(ft_split(line, ' '));
		free(line);
		new = ft_lstnew(int_tab);
		ft_lstadd_back(&first, new);
	}
	free(new);
	return (ft_get_int_tab(first));
}
