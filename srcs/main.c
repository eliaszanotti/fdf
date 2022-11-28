/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:00:59 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 18:03:40 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(void)
{
	t_vars	window;
	int		lines;
	int		cols;
	int		fd;
	int		**tab;

	lines = 0;
	cols = 0;
	fd = open("test", O_RDONLY);
	tab = ft_parsing(fd, &lines, &cols);
	window.lines = lines;
	window.cols = cols;
	ft_display_grid(tab, window);
}
