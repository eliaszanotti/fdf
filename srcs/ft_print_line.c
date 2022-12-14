/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:12:02 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 15:21:37 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_line(t_grid *grid)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = grid->x2 - grid->x1;
	delta_y = grid->y2 - grid->y1;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = grid->x1;
	pixel_y = grid->y1;
	while (pixels--)
	{
		if ((int)pixel_y * WIN_W + (int)pixel_x < WIN_W * WIN_H && \
				(int)pixel_x < WIN_W && (int)pixel_x > 0 && \
				(int)pixel_y < WIN_H && (int)pixel_y > 0)
			grid->image.data[(int)pixel_y * WIN_W + (int)pixel_x] = \
				grid->color;
		pixel_x += delta_x;
		pixel_y += delta_y;
	}
}
