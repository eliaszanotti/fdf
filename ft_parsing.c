/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:00:27 by ezanotti          #+#    #+#             */
/*   Updated: 2022/11/24 18:33:07 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_parsing(int fd)
{
	char	*full_line;
	char	*new_line;

	full_line = ft_calloc(1, sizeof(char));
	new_line = get_next_line(fd);
	while (new_line)
	{	
		full_line = ft_join_buffer(full_line, new_line);
		new_line = get_next_line(fd);
	}
	return (full_line);




	/*while (1)
		strjoin(char_s, get_next_line(fd));*/

	// ici on a une char * super longue avec tout le fichier 




}
