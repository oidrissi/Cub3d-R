/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:42:29 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/23 20:48:57 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// neo parser

/*
* Entry point of my program :
*
* -->  Error handling / Parsing :
*
* If arguments count != 2 : print error on stderr.
*
* --> Init variables class / map class.
*
* Check map extension : check_extension();
*
* Check if argument value of argv[1] has a .cub extension.
*
* read_buffer() : read content of the map with gnl.
*/

int	mlx_core(t_variables *vars)
{
	printf("\n\nStarting mlx ...\n\n");
	if (init_vars_class(vars))
	{
		free_all(vars);
		exit_perror(MALLOC_ERR);
	}
	mlx_initialize(vars);
	mlx_hook(vars->window, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->window, 17, 1L << 17, close_window, vars);
	/* FUNCTION TO DRAW IN WINDOW*/
	ft_draw(vars);
	mlx_loop(vars->mlx);
	free_all(vars);
	return (0x0);
}

/*
 * initialize map :
*/

void	map_initialize(t_map *map)
{
	map->buffered = 0x0;
	map->width = 0x0;
	map->north = 0x0;
	map->south = 0x0;
	map->west = 0x0;
	map->east = 0x0;
	map->floor_rgb = 0x0;
	map->celling_rgb = 0x0;
	map->map_lines = 0x0;
	map->counter = 0x0;
}

// TASK : WORKING ON MLX CORE !
// -> Render 2D map.

int	main(int argc, char **argv)
{
	t_variables	vars;

	(void)	argv;
	if (argc != 2)
		return (return_error(USAGE, EXIT_FAILURE));
	//vars = (t_variables *) malloc (sizeof(t_variables));
	/*
	 * INIT MAP :
	*/
	map_initialize(&vars.map);
	if (check_extension(argv[1]) != 0x0)
		return (EXIT_FAILURE);
	if (read_buffer(argv[1], &vars.map) != 0x0)
		return (EXIT_FAILURE);
	/*
	 * PARSER :
	*/
	if (parse_data(&vars.map, argv[1]) != 0x0)
		return (EXIT_FAILURE);
	mlx_core(&vars);
	return (EXIT_SUCCESS);
}
