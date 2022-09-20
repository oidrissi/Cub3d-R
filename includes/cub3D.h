/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:20:56 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/20 10:31:23 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* Standard Libs*/
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

/*Standard unix lib*/

# include <unistd.h>

/*lib to include open() system call*/

# include <fcntl.h>

/* Mathematical funtions*/

# include <math.h>

/*Minilibx library*/

# include <mlx.h>

/*s_map class :
 *
 * *floor_rgb : floor RGB colors.
 *
 * *celling_rgb " celling RGB colors.
 *
 * *sprite : sprite texture path.
 *
 * resolution[2] : resolution of the window defined on the map file.
 *
 * *North, *South, *West, *East : directions of different map textures.
 *
 * char **buffer : map elements.
 *
*/

# define USAGE "Usage : ./cub3D [map.cub]\n"
# define MAP_EXTENSION "Error : Invalid map extension\n"
# define ERR -1
# define MAP_EMPTY "Error : empty map\n"
# define FATAL_ERROR "Error : fatal error\n"

typedef struct s_map
{
	int		resolution[2];
	char	**buffered;
	int		width;
	int		height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	*floor_rgb;
	char	*celling_rgb;
}	t_map;


typedef struct s_variables
{
	t_map	map;
}	t_variables;

/*
 * Entry point of cub3d / Error handling
*/

int	main(int argc, char **argv);
int	return_error(char *string, int exit_code);
int	check_extension(char *string);
int	read_buffer(char *str, t_map *map);
int	perror_return(char *str, int exit_code);
int	buffer_fill(char *str, int lines, t_map *map);

/*
 * Read map character by character via get_next_line with one buffersize.
*/

# define BUFFER_SIZE 1024

char	*ft_get_next_line(int fd);

/*
 * Libft utils :
*/

int		ft_strlen(char *str);
char	*ft_strrev(char *str);
char	*ft_strdup(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strncmp(char *s1, char *s2, int n);


#endif