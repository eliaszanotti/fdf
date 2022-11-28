/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:10 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 16:09:18 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	ft_display_grid(int **tab, int lines, int cols)
{
	t_vars	window;
	t_line	line;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 1920, 1080, "Fil De Fer");

	int i = 0;
	int j = 0;

	while (i < lines)
	{
		j = 0;
		while (j < cols)
		{
			
			line.x1 = (j - i) * 50 + 600;
			line.y1 = (i + j) * 33 + 50;
			line.x2 = line.x1 + 50;
			line.y2 = line.y1 + 33;
			if (j != cols - 1)
				ft_print_line(window, line);
			line.x2 = line.x2 - 100;
			if (i != lines - 1)
				ft_print_line(window, line);
			tab = NULL;
			//mlx_string_put(window.mlx, window.win, line.x1, line.y1, 0255000000, ft_itoa(tab[i][j] * 1000));
			j++;
		}
		i++;
	}
	//mlx_destroy_window(mlx, mlx_win);
	//mlx_destroy_display(mlx);
	mlx_loop(window.mlx);
}
