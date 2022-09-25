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


/*
 * Omar Parser
 * 1 - Checking the extension of the file
 * It should end with .cub
 * It can have multiple .cub but it should end with .cub and '\0' and not start with .
*/

int	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
			return (0);
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b' && str[i + 4] == '\0')
		return (return_error(MAP_EXTENSION, EXIT_FAILURE));
	return (0);
}

/*
 * Checks that the top part of the file is formatted correctly.
*/


void retrieve_textures(t_variables vars, char *file)
{
	int		fd;
	char	*line;
	int		i;
	
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd <= ERR)
		return (perror_return(file, EXIT_FAILURE));
	line = ft_get_next_line(fd);
	check_north_texture(vars, line);
	free(line);
	line = ft_get_next_line(fd);
	retrieve_south_texture(vars, line);
	free(line);
	line = ft_get_next_line(fd);
	retrieve_west_texture(vars, line);
	free(line);
	line = ft_get_next_line(fd);
	retrieve_east_texture(vars, line);
	free(line);
}

void retrieve_north_texture(char *str)
{
}

void retrieve_south_texture(char *str)
{

}

void retrieve_west_texture(char *str)
{

}

void retrieve_east_texture(char *str)
{

}


bool check_top(char *str)
{
	
}