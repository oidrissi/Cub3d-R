/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:42:29 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/20 10:41:28 by ablaamim         ###   ########.fr       */
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
*/

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
	return (EXIT_SUCCESS);
}
