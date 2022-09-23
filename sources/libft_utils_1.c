/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 08:49:15 by ablaamim          #+#    #+#             */
/*   Updated: 2022/09/23 21:09:52 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

size_t	ft_strlen(char const *str)
{
	size_t	len;

	len = 0x0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strrev(char *str)
{
	char	temp;
	char	*start;
	char	*end;

	start = str;
	end = str + (ft_strlen(str) - 1);
	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (save);
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		len;

	len = ft_strlen(str);
	new = malloc(len + 0x1);
	if (!new)
		return (0x0);
	return (ft_strcpy(new, str));
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0x0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i < n)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	else
		return (0x0);
}
