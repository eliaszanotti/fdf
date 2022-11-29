/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:59 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/29 16:39:19 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_grid	*grid;
	int		fd;
	
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	grid = ft_grid_init(fd);
	printf("%d, %d\n", grid->off_left, grid->off_top);
	ft_display_grid(grid);
}
