/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:20:56 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/23 21:18:22 by ablaamim         ###   ########.fr       */
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

# define USAGE "Usage : ./cub3D [map.cub]\n"
# define MAP_EXTENSION "Error : Invalid map extension\n"
# define ERR -1
# define MAP_EMPTY "Error : empty map\n"
# define FATAL_ERROR "Error : fatal error\n"
# define QUIT_MLX "Mlx closing : Quit Process ...\n\n"
# define MALLOC_ERR "Error : System malloc() failed\n"
# define TEXTURE_ERR "Error : Invalid texture file\n"
/*
 * RESOLUTOON : 
*/
# ifndef WIN_WIDTH
#  define WIN_WIDTH 1080
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1024
# endif

/*
 * Keyhook defines keypress / keyrelease are handled by mlx_key_hook():
*/

# define ESC_KEY 53
//# define R_KEY 15
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define W_KEY 13
# define S_KEY 1
# define A_KEY 0
# define D_KEY 2

/*
 * Colors MACROS :
*/

# define WHITE 0xFFFFFF

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


typedef struct s_map
{
	int		resolution[2];
	char	**map; //GRID
	char	**buffered;
	char	starting_orientation;
	int		position_index;
	int		width;
	int		height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	*floor_rgb;
	char	*celling_rgb;
	int		map_lines;
	int		index;
	int		counter;
	float	player_position[2];
}	t_map;

/*
 * Image class : mlx image struct :
 *
 * *img = pointer to image.
 * *addr = pointer to the pixel data.
 * bpp = bits per pixel.
 * line_length = len of a line of pixels in *addr.
 * endian = endian type (0 = small endian, 1 = big endian)
 *
*/

typedef struct s_image
{
	void	*image;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

/*
 * Data to init mlx :
*/

typedef struct s_variables
{
	t_map	map;
	t_image	image;
	t_image	minimap;
	void	*mlx;
	void	*window;
}	t_variables;

/*
 * Entry point of cub3d / Error handling
*/

int	main(int argc, char **argv);
int	return_error(char *string, int exit_code);
int	check_extension(char *string);
int	read_buffer(char *str, t_map *map);
int	perror_return(char *str, int exit_code);
int	buffer_fill(char *str, int map_lines, t_map *map);

/*
 * PARSER METHOD :
*/

int	parse_data(t_map *map, char *argv);

/*
 * Read map character by character via get_next_line with one buffersize.
*/

# define BUFFER_SIZE 1024

char	*ft_get_next_line(int fd);

/*
 * Libft utils :
*/

size_t	ft_strlen(char const *str);
char	*ft_strrev(char *str);
char	*ft_strdup(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strncmp(char *s1, char *s2, int n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *memory, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


/*
 * mlx core functions :
*/

int		mlx_core(t_variables *vars);
int		init_vars_class(t_variables *vars);
int		exit_perror(char *str);
void	free_all(t_variables *vars);
void	mlx_initialize(t_variables *vars);

/*
 * MLX HOOKS :
*/

int	key_hook(int key_code, t_variables *vars);
int	close_window(t_variables *vars);

/*
 * PUT PIXEL TO IMAGE / RENDER.
*/

void	ft_draw(t_variables *vars);

/*
 * MLX TRAINING AS A FIRST QUEST : draw a menu!!
*/

void	ft_render_menu(t_variables *vars);

#endif
