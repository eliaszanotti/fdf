/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:51:01 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/30 10:51:18 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_place_line(t_vars *window, t_grid *grid, int i, int j)
{
	grid->x1 = (j - i) * grid->max + grid->off_left;
	grid->y1 = ((i + j) * grid->min + grid->off_top) - \
			(grid->tab[i][j] * grid->altitude);
	grid->x2 = grid->x1 + grid->max;
	grid->y2 = grid->y1 + grid->min;
	if (j + 1 != grid->cols)
		grid->y2 = (grid->y1 + grid->min) - \
			(grid->tab[i][j + 1] * grid->altitude) + \
			(grid->tab[i][j] * grid->altitude);
	if (j != grid->cols - 1)
		ft_print_line(window, grid);
	grid->x2 = grid->x1 - grid->max;
	if (i + 1 != grid->lines)
		grid->y2 = grid->y1 + grid->min - \
			(grid->tab[i + 1][j] * grid->altitude) + \
			(grid->tab[i][j] * grid->altitude);
	if (i != grid->lines - 1)
		ft_print_line(window, grid);
}
