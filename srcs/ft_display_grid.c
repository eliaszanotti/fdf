/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:10 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 18:50:51 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX 7
#define MIN 4

void	ft_place_line(t_vars window, t_offset offset, int i, int j)
{
	t_line	line;

	line.x1 = (j - i) * MAX + offset.left + offset.left_offset;
	line.y1 = (i + j) * MIN + offset.top_offset;
	line.x2 = line.x1 + MAX;
	line.y2 = line.y1 + MIN;
	if (j != window.cols - 1)
		ft_print_line(window, line);
	line.x2 = line.x2 - (MAX * 2);
	if (i != window.lines - 1)
		ft_print_line(window, line);
	//mlx_string_put(window.mlx, window.win, line.x1, line.y1, 0255000000, ft_itoa(line.y1));
}

void	ft_display_grid(int **tab, t_vars window)
{
	t_offset	offset;
	int			i;
	int			j;

	offset.left = (window.lines - 1) * MAX;
	offset.top = (window.lines + window.cols - 2) * MIN;
	offset.left_offset = (1920 - ((window.lines + window.cols) * MAX)) / 2;
	offset.top_offset = (1080 - offset.top) / 2;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, 1920, 1080, "Fil De Fer");
	i = 0;
	while (i < window.lines)
	{
		j = 0;
		while (j < window.cols)
			ft_place_line(window, offset, i, j++);
		i++;
	}
	//mlx_destroy_window(mlx, mlx_win);
	//mlx_destroy_display(mlx);
	mlx_loop(window.mlx);
	tab = NULL;
}
