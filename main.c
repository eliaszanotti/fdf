/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:51:29 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 12:04:49 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"

#include <stdio.h>
#include <fcntl.h>

void put(int *tab)
{
	int i = 0;

	while (i < 4)
		printf("[%d]", tab[i++]);
	printf("\n");
}

int main()
{
	int fd = open("test", O_RDONLY);
	int **new_tab = ft_parsing(fd);
	int i = 0;
	while (i < 4)
	{
		put(new_tab[i]);
		i++;
	}

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2000, 1000, "Hello world!");
	mlx_pixel_put(mlx, mlx_win, 100, 100, 255);

	i = 0;
	int j = 0;
	int px = 0;
	int py = 0;

	while (i < 11)
	{
		j = 0;
		while (j < 20)
		{
			printf("%d ", new_tab[i][j]);
			px = (j - i) * 50 + 600;
			py = (i + j) * 25 + 200;
			
			mlx_string_put(mlx, mlx_win, px, py, 0255000000, ft_itoa(new_tab[i][j] * 1000));
			j++;
		}
		i++;
	
	}


	//mlx_destroy_window(mlx, mlx_win);
	//mlx_destroy_display(mlx);
	mlx_loop(mlx);
}
