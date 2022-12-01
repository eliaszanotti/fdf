/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:28:36 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 14:33:05 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


#include <stdio.h>

int	ft_key_hook(int key, t_grid *grid)
{

	printf("%d\n", key);

	//mlx_destroy_image(grid->mlx, grid->image.img);
	//ft_update_map(grid);
	(void)grid;
	return (0);
}

int ft_mouse_hook(int key, int x, int y, t_grid *grid)
{
	x = 0;
	y = 0;
	if (key == 5)
		grid->max += 1;
	if (key == 4 && grid->max > 1)
		grid->max -= 1;

	/*grid->left = (grid->lines - 1) * grid->max;
	grid->top = (grid->lines + grid->cols - 2) * grid->min;
	grid->off_left = grid->left + \
		(WIN_W - ((grid->lines + grid->cols) * grid->max)) / 2;
	grid->off_top = (WIN_H - grid->top) / 2;*/

	mlx_destroy_image(grid->mlx, grid->image.img);
	ft_update_map(grid);
	return (0);
}
