/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 08:50:11 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/24 17:14:59 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# include "libft.h"

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

void	*ft_calloc_gnl(size_t count, size_t size);
char	*ft_strjoin_gnl(char const *s1, char const *s2);

#endif
