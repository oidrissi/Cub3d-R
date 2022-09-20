/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:14:16 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/20 10:17:02 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_get_next_line(int fd)
{
	int		bytes;
	char	buff;
	int		i = 0x0;
	char	heap[5000];

	if (fd < 0x0 || BUFFER_SIZE <= 0x0)
		return(0x0);
	while ((bytes = read(fd, &buff, 1)) && bytes > 0)
	{
		heap[i++] = buff;
		if (buff == '\n' || !buff)
			break;
	}
	heap[i] = '\0';
	if (i == 0 && bytes >= 0)
		return (0x0);
	return (ft_strdup(heap));
}
