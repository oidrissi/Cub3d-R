/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:44:45 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/20 11:49:09 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_vars(t_variables *vars)
{
	(void) vars;
}

void	free_all(t_variables *vars)
{
	mlx_destroy_window(vars->mlx, vars->window);
	mlx_destroy_image(vars->mlx, vars->image.image);
	free_vars(vars);
}

void	reset_variables(t_variables *vars)
{
	(void) vars;
}

int	init_vars_class(t_variables *vars)
{
	reset_variables(vars);
	return (0x0);
}
