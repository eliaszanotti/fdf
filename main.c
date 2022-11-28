/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:51:29 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 10:54:29 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"

#include <stdio.h>
#include <fcntl.h>

void put(int *tab)
{
	int i = 0;

	while (tab[i])
		printf("[%d]", tab[i++]);
	printf("\n");
}

int main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);



	int fd = open("test", O_RDONLY);
	int **new_tab = ft_parsing(fd);
	
	int i = 0;
	while (new_tab[i])
	{
		put(new_tab[i]);
		free(new_tab[i]);
		i++;
	}
	free(new_tab);
}
