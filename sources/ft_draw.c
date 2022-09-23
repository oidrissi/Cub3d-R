/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:11:50 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/23 21:19:57 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
 * As a first challenge i decided to draw a menu inside the window.
 *
 * -> Getting used again to mlx functions.
 *
*/

void	ft_render_menu(t_variables *vars)
{
	int		y_location;
	void	*mlx;
	void	*window;

	y_location = 0x0;
	mlx = vars->mlx;
	window = vars->window;
	mlx_string_put(mlx, window, 20, y_location += 30, WHITE, " - Keyboard controls - ");
	mlx_string_put(mlx, window, 20, y_location += 50, WHITE, \
			"Close windows  : ESC Button");
	// NOT FINISHED, I should draw more informations.
}

/*
 * Render Minimap
*/

void	render_minimap(t_variables *vars)
{
	(void) vars;
}

/*
 * Manipulating images with mlx lib in order to draw inside the window.
*/

void	ft_draw(t_variables *vars)
{
	ft_bzero(vars->image.addr, WIN_WIDTH / WIN_HEIGHT / (vars->image.bpp / 8));
	render_minimap(vars);
	/*
	 * Put an image inside a given window.
	*/
	mlx_put_image_to_window(vars->mlx, vars->window, vars->image.image, 0x0, 0x0);
	ft_render_menu(vars);
}
