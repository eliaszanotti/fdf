/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:10 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 15:17:12 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	ft_display_grid(int **tab)
{
	t_vars	window;
	t_line	line;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 1920, 1080, "Fil De Fer");

	int i = 0;
	int j = 0;
	//int px = (j - i) * 50 + 600; 
	//int py = (i + j) * 33 + 50;

	while (i < 11)
	{
		j = 0;
		while (j < 20)
		{
			line.x1 = (j - i) * 50 + 600;
			line.y1 = (i + j) * 33 + 50;
			line.x2 = line.x1 + 50;
			line.y2 = line.y1 + 33;
			ft_print_line(window, line);
			line.x2 = line.x2 - 100;
			ft_print_line(window, line);
			printf("%d", tab[i][j]);
			mlx_string_put(window.mlx, window.win, line.x1, line.y1, 0255000000, ft_itoa(tab[i][j] * 1000));
			j++;
		}
		i++;
	}
	
	/*line.x1 = 600;
	line.y1 = 200;
	line.x2 = 650;
	line.y2 = 250;


	ft_print_line(window, line);*/

	//mlx_destroy_window(mlx, mlx_win);
	//mlx_destroy_display(mlx);
	mlx_loop(window.mlx);

}
