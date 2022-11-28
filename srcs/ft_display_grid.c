/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:10 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 18:37:28 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX 7
#define MIN 4

#include <stdio.h>

void	ft_display_grid(int **tab, t_vars window)
{
	t_line	line;
	int left = (window.lines - 1) * MAX;	
	int top = (window.lines + window.cols - 2) * MIN;
	int left_offset = (1920 - ((window.lines + window.cols) * MAX)) / 2;
	int top_offset = (1080 - top) / 2;
	int i = 0;
	int j = 0;

	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 1920, 1080, "Fil De Fer");
	while (i < window.lines)
	{
		j = 0;
		while (j < window.cols)
		{
			line.x1 = (j - i) * MAX + left + left_offset;
			line.y1 = (i + j) * MIN + top_offset;
			line.x2 = line.x1 + MAX;
			line.y2 = line.y1 + MIN;
			if (j != window.cols - 1)
				ft_print_line(window, line);
			line.x2 = line.x2 - (MAX * 2);
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
