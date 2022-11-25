/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:00:27 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/24 18:33:07 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_get_full_line(int fd)
{
	char	*full_line;
	char	*new_line;

	full_line = ft_calloc(1, sizeof(char));
	new_line = get_next_line(fd);
	while (new_line)
	{	
		full_line = ft_join_buffer(full_line, new_line);
		new_line = get_next_line(fd);
	}
	return (full_line);
}

size_t	ft_get_line_width(char **line_splited)
{
	size_t	i;
	

	i = 0;
	while (line_splited[i])
	{
		if (ft_isnl(line_splited[i]))
			break;

		i++;
	}
	return (i);
}


int		*ft_get_atoi_tab(char **tab)
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

int	*ft_parsing(int fd)
{
	char	*full_line;
	char	**line_splited;	
	size_t	line_width;
	int		*int_tab;

	full_line = ft_get_full_line(fd);
	line_splited = ft_split(full_line, ' ');
	line_width = ft_get_line_width(line_splited);
	printf("%zu\n\n", line_width);




	int i = 0;
	while (line_splited[i])
		printf("<%s>", line_splited[i++]);

	


	free(full_line);
	int_tab = ft_get_atoi_tab(line_splited);



	return (int_tab);
	/*while (1)
		strjoin(char_s, get_next_line(fd));*/
	// ici on a une char * super longue avec tout le fichier 
}
