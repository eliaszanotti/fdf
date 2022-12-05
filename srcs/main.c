/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:59 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 08:51:35 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_grid	*grid;
	int		fd;

	if (argc != 2)
	{
		ft_putendl_fd("Error: Please enter only 1 argument", 1);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("Error: C'ant open file", 1);
		return (0);
	}
	grid = ft_struct_init(fd);
	if (!grid)
		return (0);
	ft_create_map(grid);
	mlx_loop(grid->mlx);
	return (0);
}
