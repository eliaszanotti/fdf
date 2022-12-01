/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:10 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 12:47:52 by ezanotti         ###   ########lyon.fr   */
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
	if (key == 4 && grid->max > 3)
		grid->max -= 1;

	grid->min = grid->max * grid->rotation;

	/*grid->left = (grid->lines - 1) * grid->max;
	grid->top = (grid->lines + grid->cols - 2) * grid->min;
	grid->off_left = grid->left + \
		(WIN_W - ((grid->lines + grid->cols) * grid->max)) / 2;
	grid->off_top = (WIN_H - grid->top) / 2;*/

	mlx_destroy_image(grid->mlx, grid->image.img);
	ft_update_map(grid);
	return (0);
}

void	ft_update_map(t_grid *grid)
{
	int		i;
	int		j;
	
	grid->image.img = mlx_new_image(grid->mlx, WIN_W, WIN_H);
	grid->image.data = (int *)mlx_get_data_addr(grid->image.img, \
		&grid->image.bpp, &grid->image.size_l, &grid->image.endian);
	i = 0;
	while (i < grid->lines)
	{
		j = 0;
		while (j < grid->cols)
		{
			grid->color = ft_color(grid, i, j);
			ft_place_line(grid, i, j++);
		}
		i++;
	}
	mlx_put_image_to_window(grid->mlx, grid->win, grid->image.img, 0, 0);
}

void	ft_create_map(t_grid *grid)
{

	ft_update_map(grid);
	mlx_key_hook(grid->win, ft_key_hook, grid);
	mlx_mouse_hook(grid->win, ft_mouse_hook, grid);
	//mlx_hook(grid->win, 5, 0, ft_close, grid);	
}
