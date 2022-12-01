/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:07:28 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/01 15:35:05 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# ifndef WIN_W
#  define WIN_W 2570
# endif
# ifndef WIN_H
#  define WIN_H 1440
# endif

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_grid
{
	void	*mlx;
	void	*win;
	t_img	image;
	int		**tab;
	int		lines;
	int		cols;
	int		max;
	double	altitude;
	int		off_left;
	int		off_top;
	int		color;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}	t_grid;

int		ft_color(t_grid *grid, int i, int j);
void	ft_create_map(t_grid *grid);
void	ft_update_map(t_grid *grid);
int		**ft_parsing(int fd, t_grid *grid);
void	ft_place_line(t_grid *grid, int i, int j);
void	ft_print_line(t_grid *grid);
t_grid	*ft_struct_init(int fd);
int		ft_key_hook(int key, t_grid *grid);
int		ft_mouse_hook(int key, int x, int y, t_grid *grid);
int		ft_exit(t_grid *grid);

#endif
