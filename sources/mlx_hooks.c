/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:26:49 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/23 17:05:05 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	close_window(t_variables *vars)
{
	free_all(vars);
	write(2, QUIT_MLX, sizeof(QUIT_MLX));
	exit(EXIT_SUCCESS);
	return (0x0);
}

int	key_hook(int key_hook, t_variables *vars)
{
	if (key_hook == ESC_KEY)
		close_window(vars);
	return (0x0);
}
