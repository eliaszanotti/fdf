/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:13:58 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 14:27:54 by ezanotti         ###   ########lyon.fr   */
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
	grid->off_left = (WIN_W - ((grid->lines + grid->cols) * grid->max) / \
		sqrt(2)) / 2;
	grid->off_left += (grid->lines * grid->max / sqrt(2));
	grid->off_top = (WIN_H - (grid->max * (grid->lines + grid->cols)) / \
		sqrt(6)) / 2;
	grid->altitude = 1;
	return (grid);
}
