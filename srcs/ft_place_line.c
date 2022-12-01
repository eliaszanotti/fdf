/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:51:01 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 14:08:40 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_place_line(t_grid *grid, int i, int j)
{
	grid->x1 = grid->off_left + (grid->max * (j - i)) / sqrt(2);
	grid->y1 = grid->off_top - (grid->tab[i][j] * grid->altitude)
		+ (grid->max * (i + j)) / sqrt(6);
	if (j + 1 < grid->cols)
	{
		grid->x2 = grid->off_left + ((grid->max * (j + 1)) - (grid->max * i)) \
			/ sqrt(2);
		grid->y2 = grid->off_top - (grid->tab[i][j + 1] * grid->altitude) \
			+ ((grid->max * i) + (grid->max * (j + 1))) / sqrt(6);
		ft_print_line(grid);
	}
	if (i + 1 < grid->lines)
	{
		grid->x2 = grid->off_left + ((grid->max * j) - (grid->max * (i + 1))) \
			/ sqrt(2);
		grid->y2 = grid->off_top - (grid->tab[i + 1][j] * grid->altitude) \
			+ ((grid->max * (i + 1)) + (grid->max * j)) / sqrt(6);
		ft_print_line(grid);
	}
}
