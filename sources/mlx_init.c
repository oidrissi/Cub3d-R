/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:31:31 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/23 17:02:54 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
 * Init mlx funtions :
*/

void	mlx_initialize(t_variables *vars)
{
	vars->mlx = mlx_init();
	vars->image.image = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->image.addr = mlx_get_data_addr(vars->image.image, &vars->image.bpp, \
			&vars->image.line_length, &vars->image.endian);
	vars->window = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
}
