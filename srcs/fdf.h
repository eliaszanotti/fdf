/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:07:28 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/28 18:51:11 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		lines;
	int		cols;
}	t_vars;

typedef struct s_line
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_line;

typedef struct s_offset
{
	int	left;
	int	top;
	int	left_offset;
	int	top_offset;
}	t_offset;

int		**ft_parsing(int fd, int *lines, int *cols);
void	ft_display_grid(int **tab, t_vars window);
void	ft_print_line(t_vars window, t_line line);

#endif
