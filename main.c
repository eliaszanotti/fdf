/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:51:29 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/26 09:53:40 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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



	int fd = open("test", O_RDONLY);
	int **new_tab = ft_parsing(fd);
	
	int i = 0;
	while (new_tab[i])
	{
		put(new_tab[i]);
		i++;
	}
	free(new_tab);
}
