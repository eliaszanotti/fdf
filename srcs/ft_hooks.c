/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:36 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 15:41:05 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


#include <stdio.h>

int	ft_key_hook(int key, t_grid *grid)
{
	int	move;

	move = 250;
	printf("%d\n", key);
	if (key == 53)
		ft_exit(grid);
	if (key == 126)
		grid->off_top += move;
	if (key == 125)
		grid->off_top -= move;
	if (key == 123)
		grid->off_left += move;
	if (key == 124)
		grid->off_left -= move;
	if (key >= 82 && key <= 85)
		grid->altitude = -1 * (82 - key);
	if (key == 69)
		grid->altitude += 0.1;
	if (key == 78 && grid->altitude > 0.1)
		grid->altitude -= 0.1;
	mlx_destroy_image(grid->mlx, grid->image.img);
	ft_update_map(grid);
	return (0);
}

int	ft_mouse_hook(int key, int x, int y, t_grid *grid)
{
	if (key == 5)
	{
		grid->max += 1;
		if (grid->altitude > 0.1)
			grid->altitude += 0.1;
	}
	if (key == 4 && grid->max > 1)
	{
		grid->max -= 1;
		if (grid->altitude >= 0.1)
			grid->altitude -= 0.1;
	}
	grid->off_left = (WIN_W - ((grid->lines + grid->cols) * grid->max) / \
		sqrt(2)) / 2;
	grid->off_left += (grid->lines * grid->max / sqrt(2));
	grid->off_top = (WIN_H - (grid->max * (grid->lines + grid->cols)) / \
		sqrt(6)) / 2;
	mlx_destroy_image(grid->mlx, grid->image.img);
	ft_update_map(grid);
	x = 0;
	y = 0;
	return (0);
}
