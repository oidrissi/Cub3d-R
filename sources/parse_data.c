/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:45:43 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/23 21:13:47 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
 * Parse all data components :
*/

int	parse_data(t_map *map, char *argv)
{
	if (map->map_lines == 0x0)
		return (return_error(MAP_EMPTY, EXIT_FAILURE));
	if (buffer_fill(argv, map->map_lines, map) < 0x0)
		return (return_error(FATAL_ERROR, EXIT_FAILURE));
	//if (textures_parser(map) < 0x0)
		//return (return_error(TEXTURE_ERR, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
