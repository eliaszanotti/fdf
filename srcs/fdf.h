/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:07:28 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/30 10:54:30 by ezanotti         ###   ########lyon.fr   */
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

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	image;
}	t_vars;

typedef struct s_grid
{
	int		**tab;
	int		lines;
	int		cols;
	int		max;
	double	altitude;
	double	rotation;
	int		min;
	int		left;
	int		top;
	int		off_left;
	int		off_top;
	int		color;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}	t_grid;

int		ft_color(t_grid *grid, int i, int j);
void	ft_display_grid(t_grid *grid);
int		**ft_parsing(int fd, t_grid *grid);
void	ft_place_line(t_vars *window, t_grid *grid, int i, int j);
void	ft_print_line(t_vars *window, t_grid *grid);
t_grid	*ft_grid_init(int fd);
t_vars	*ft_window_init(char *title);

#endif
