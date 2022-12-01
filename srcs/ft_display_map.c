/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:10 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 10:02:54 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	ft_key_hook(int key, t_grid *grid)
{
	printf("%d\n", key);
	if (key == 69)
		grid->max += 1;	
	if (key == 78)
		grid->max -= 1;
	if (key == 126)
		grid->altitude += 0.2;
	if (key == 125 && grid->altitude >= 0.2)
		grid->altitude -= 0.2;
	grid->min = round(grid->max * grid->rotation);
	grid->left = (grid->lines - 1) * grid->max;
	grid->top = (grid->lines + grid->cols - 2) * grid->min;
	grid->off_left = grid->left + \
		(WIN_W - ((grid->lines + grid->cols) * grid->max)) / 2;
	grid->off_top = (WIN_H - grid->top) / 2;


	mlx_destroy_image(grid->mlx, grid->image.img);
	ft_update_map(grid);
	return (0);
}

/*int	ft_mouse_hook(int key, t_grid *grid)
{
	printf("\t%d\n", key);
	//if (key == 3)
	//	grid->altitude += 0.1;
	//mlx_destroy_image(grid->mlx, grid->image.img);
	//ft_update_map(grid);
	mlx_destroy_image(grid->mlx, grid->image.img);
	ft_update_map(grid);
	//(void)grid;
	return (0);
}*/

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
	//mlx_mouse_hook(grid->win, ft_mouse_hook, grid);
	mlx_key_hook(grid->win, ft_key_hook, grid);
}
