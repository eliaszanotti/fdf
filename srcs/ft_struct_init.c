/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:13:58 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/29 14:34:44 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

#define MAX 3
#define MIN 2

t_grid	*ft_grid_init(int fd)
{
	t_grid	*grid;

	grid = malloc(sizeof(t_grid));
	if (!grid)
		return (NULL);
	grid->tab = ft_parsing(fd, grid);
	grid->left = (grid->lines - 1) * MAX;
	grid->top = (grid->lines + grid->cols - 2) * MIN;
	grid->off_left = grid->left + \
		(WIN_W - ((grid->lines + grid->cols) * MAX)) / 2;
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
	return (window);
}
