/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:13:58 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/30 15:49:03 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_grid	*ft_struct_init(int fd)
{
	t_grid	*grid;

	grid = malloc(sizeof(t_grid));
	if (!grid)
		return (NULL);
	grid->mlx = mlx_init();
	grid->win = mlx_new_window(grid->mlx, WIN_W, WIN_H, "FDF");
	grid->tab = ft_parsing(fd, grid);
	grid->max = round(((WIN_W + WIN_H) / 2) / (grid->lines + grid->cols - 2));
	grid->altitude = 1;
	grid->rotation = 0.7;
	grid->min = round(grid->max * grid->rotation);
	grid->left = (grid->lines - 1) * grid->max;
	grid->top = (grid->lines + grid->cols - 2) * grid->min;
	grid->off_left = grid->left + \
		(WIN_W - ((grid->lines + grid->cols) * grid->max)) / 2;
	grid->off_top = (WIN_H - grid->top) / 2;
	return (grid);
}
