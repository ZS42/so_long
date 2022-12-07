/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_char_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 09:58:00 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/23 15:07:01 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_valid_char(t_map map)
{
	int	i;

	i = 0;
	while (map.str_map[i])
	{
		if (!(map.str_map[i] == 'C' || map.str_map[i] == '0'
				|| map.str_map[i] == 'P' || map.str_map[i] == 'E'
				|| map.str_map[i] == '1' || map.str_map[i] == 'D'
				|| map.str_map[i] == '\n'))
		{
			perror("Error\n invalid character on map");
			free(map.str_map);
			exit (0);
		}
		i++;
	}
}

void	error_message(t_map *map)
{
	perror("Error\n invalid wall");
	free (map->str_map);
	exit (0);
}

void	ft_valid_wall_helper(t_map *map, int w, int h)
{
	int	i;

	i = 0;
	while (i < ft_strlen(map->str_map))
	{
		if (i == 0 || map->str_map[i + 1] == '\0')
		{
			if (map->str_map[i] != '1')
				error_message(map);
		}
		else if (map->str_map[i + 1] == '\n')
		{
			if (map->str_map[i] != '1' || map->str_map[i + 2] != '1')
				error_message(map);
		}
		else if (i < w - 1 || i > (w * (h)))
		{
			if (map->str_map[i] != '1')
				error_message(map);
		}
		i++;
	}
}

void	ft_valid_wall(t_map *map)
{
	int	h;
	int	w;

	w = map->width + 1;
	h = map->height;
	ft_valid_wall_helper(map, w, h);
}
