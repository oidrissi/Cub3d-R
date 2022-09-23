/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:12:18 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/23 21:10:08 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
 * Fill Buffer 2d array in t_map class via gnl() and check errors.
 *
*/

int	buffer_fill(char *file, int map_lines, t_map *map)
{
	int		fd;
	int		i;
	char	*s;

	i = -1;
	map->buffered = (char **) malloc(sizeof(char *) * (map_lines + 0x1));
	if (map->buffered == 0x0)
		return (EXIT_FAILURE);
	fd = open(file, O_RDONLY);
	if (fd <= ERR)
		return (EXIT_FAILURE);
	while (++i < map_lines)
	{
		s = ft_get_next_line(fd);
		//printf("BUFFER = %s\n", map->buffered[i]);
		map->buffered[i] = ft_substr(s, 0x0, ft_strlen(s) - 1);
	}
	map->buffered[i] = 0x0;
	close(fd);
	return (0x0);
}

/*
 * Read map :
*/

int	read_buffer(char *str, t_map *map)
{
	char	*auxiliar;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd <= ERR)
		return (perror_return(str, EXIT_FAILURE));
	auxiliar = ft_get_next_line(fd);
	while (auxiliar)
	{
		++map->map_lines;
		free(auxiliar);
		auxiliar = ft_get_next_line(fd);
	}
	close(fd);
	return (0x0);
}

/*
 * Verify validity of map extention : .cub and name does not start with '.'
 * .cub.cub = hidden file.
 * map.cub = valid map.
 * map.cub[* != .cub] = invalid map.
*/

int	check_extension(char *string)
{
	char	*temp;

	temp = ft_strdup(string);
	ft_strrev(temp);
	if (ft_strncmp(temp, "buc.", 4) != 0x0 || string[0] == '.')
	{
		free(temp);
		return (return_error(MAP_EXTENSION, EXIT_FAILURE));
	}
	free(temp);
	return (0x0);
}
