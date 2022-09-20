/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:31:31 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/20 11:53:59 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
 * Init mlx :
*/

void	mlx_initialize(t_variables *vars)
{
	vars->mlx = mlx_init();
	vars->image.image = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->image.addr = mlx_get_data_addr(vars->image.image, &vars->image.bpp, &vars->image.sz_l, &vars->image.endian);
	vars->window = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
}
