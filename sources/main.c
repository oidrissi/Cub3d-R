/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:42:29 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/20 11:53:42 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
* Entry point of my program :
*
* STEP 00 : Error handling / Parsing :
*
* If arguments count != 2 : print error on stderr.
*
* Check map extension : check_extension();
*
* Check if argument value of argv[1] has a .cub extension.
*
* read_buffer() : read content of the map with gnl.
*
* mlx_core() : 
*
*/

int	mlx_core(t_variables *vars)
{
	printf("Starting mlx ...\n");
	if (init_vars_class(vars))
	{
		free_all(vars);
		exit_perror("Error : malloc failed\n");
	}
	mlx_initialize(vars);
	mlx_hook(vars->window, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->window, 17, 1L << 17, close_window, vars);
	return (0x0);
}

int	main(int argc, char **argv)
{
	t_variables	vars;

	(void)	argv;
	if (argc != 2)
		return (return_error(USAGE, EXIT_FAILURE));
	if (check_extension(argv[1]) != 0x0)
		return (EXIT_FAILURE);
	if (read_buffer(argv[1], &vars.map) != 0x0)
		return (EXIT_FAILURE);
	mlx_core(&vars);
	return (EXIT_SUCCESS);
}
