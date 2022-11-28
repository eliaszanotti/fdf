/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:10 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 17:22:14 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	ft_display_grid(int **tab, t_vars window)
{
	t_line	line;

	int left = (window.lines - 1) * 30;	
	int	right = (window.cols - 1) * 30;

	int center = (1920 - (left + right)) / 2;
	printf("\n%d\n", center);

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 1920, 1080, "Fil De Fer");

	int i = 0;
	int j = 0;

		
	while (i < window.lines)
	{
		j = 0;
		while (j < window.cols)
		{
			
			line.x1 = (j - i) * 30 + left + center;
			line.y1 = (i + j) * 20 + 50;
			line.x2 = line.x1 + 30;
			line.y2 = line.y1 + 20;
			if (j != window.cols - 1)
				ft_print_line(window, line);
			line.x2 = line.x2 - 60;
			if (i != window.lines - 1)
				ft_print_line(window, line);
			//mlx_string_put(window.mlx, window.win, line.x1, line.y1, 0255000000, ft_itoa(line.y1));
			j++;
		}
		i++;
	}
	//mlx_destroy_window(mlx, mlx_win);
	//mlx_destroy_display(mlx);
	mlx_loop(window.mlx);
	tab = NULL;
}
