/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:47:59 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/30 10:48:22 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color(t_grid *grid, int i, int j)
{
	if (grid->tab[i][j] < -20)
		return (0x000066);
	if (grid->tab[i][j] < 1)
		return (0x0000B3);
	if (grid->tab[i][j] < 10)
		return (0x008000);
	if (grid->tab[i][j] < 20)
		return (0x006600);
	if (grid->tab[i][j] < 30)
		return (0xC68C53);
	if (grid->tab[i][j] < 40)
		return (0xAC7339);
	if (grid->tab[i][j] < 60)
		return (0x86592d);
	if (grid->tab[i][j] < 80)
		return (0x604020);
	if (grid->tab[i][j] < 120)
		return (0xD0D0D0);
	if (grid->tab[i][j] < 150)
		return (0xD9D9D9);
	return (0xFFFFFF);
}
