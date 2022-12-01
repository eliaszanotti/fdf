/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_grid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:39:10 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 15:21:04 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
