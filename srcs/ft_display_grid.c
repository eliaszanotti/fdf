/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:10 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/29 12:05:41 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX 30
#define MIN 20

void	ft_place_line(t_vars *window, t_grid *grid, int i, int j)
{
	grid->x1 = (j - i) * MAX + grid->off_left;
	grid->y1 = (i + j) * MIN + grid->off_top;
	grid->x2 =	grid->x1 + MAX;
	grid->y2 =	grid->y1 + MIN;
	if (j != grid->cols - 1)
		ft_print_line(window, grid);
	grid->x2 = grid->x2 - (MAX * 2);
	if (i != grid->lines - 1)
		ft_print_line(window, grid);
}

void	ft_display_grid(t_grid *grid)
{
	t_vars	*window;
	int		i;
	int		j;

	window = ft_window_init("Fil De Fer");
	i = 0;
	while (i < grid->lines)
	{
		j = 0;
		while (j < grid->cols)
			ft_place_line(window, grid, i, j++);
		i++;
	}
	//mlx_destroy_window(mlx, mlx_win);
	//mlx_destroy_display(mlx);
	mlx_loop(window->mlx);
}
