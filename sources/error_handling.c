/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:45:59 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/20 10:26:34 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

/*
 * Return with custom error code :
*/

int	perror_return(char *str, int exit_code)
{
	if (str == 0x0)
		perror ("cub3D");
	else
		perror(str);
	return(exit_code);
}

int	return_error(char *string, int exit_code)
{
	write(2, string, ft_strlen(string));
	return(exit_code);
}
