/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:59 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 17:50:11 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void put(int *tab)
{
	int i = 0;

	while (i < 4)
		printf("[%d]", tab[i++]);
	printf("\n");
}

int main()
{
	/*int fd = open("test", O_RDONLY);
	int **new_tab = ft_parsing(fd);
	int i = 0;
	while (i < 4)
	{
		put(new_tab[i]);
		i++;
	}

	void	*mlx;
	void	*mlx_win;*/


	//t_vars	window;

	int *lines;
	int *cols;

	*lines = 0;
	*cols = 0;


	int fd = open("test", O_RDONLY);
	int **tab = ft_parsing(fd, &lines, &cols);
	printf("%d\n", *lines);

	/**window.lines = *lines;
	*window.cols = *cols;*/

	tab = 0;

	//ft_display_grid(tab, window);
}
