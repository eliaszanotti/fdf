/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:59 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/29 12:10:42 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	main(void)
{
	t_grid	*grid;
	int		fd;

	fd = open("test", O_RDONLY);
	grid = ft_grid_init(fd);
	printf("%d, %d\n", grid->off_left, grid->off_top);
	ft_display_grid(grid);
}
