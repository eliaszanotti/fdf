/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:13:58 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/29 18:37:24 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_grid	*ft_grid_init(int fd)
{
	t_grid	*grid;

	grid = malloc(sizeof(t_grid));
	if (!grid)
		return (NULL);
	grid->tab = ft_parsing(fd, grid);
	grid->max = round(((WIN_W + WIN_H) / 2) / (grid->lines + grid->cols - 2));
	grid->altitude = 0.5;
	grid->rotation = 0.5;
	grid->min = round(grid->max * grid->rotation);
	grid->left = (grid->lines - 1) * grid->max;
	grid->top = (grid->lines + grid->cols - 2) * grid->min;
	grid->off_left = grid->left + \
		(WIN_W - ((grid->lines + grid->cols) * grid->max)) / 2;
	grid->off_top = (WIN_H - grid->top) / 2;
	return (grid);
}

t_vars	*ft_window_init(char *title)
{
	t_vars	*window;

	window = malloc(sizeof(t_vars));
	if (!window)
		return (NULL);
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, WIN_W, WIN_H, title);
	window->image.img = mlx_new_image(window->mlx, WIN_W, WIN_H);
	window->image.data = (int *)mlx_get_data_addr(window->image.img, \
			&window->image.bpp, &window->image.size_l, &window->image.endian);
	return (window);
}
