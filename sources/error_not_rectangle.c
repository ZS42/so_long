/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_not_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:11:12 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/23 14:20:04 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strstr(char *h, char *n)
{
	size_t	n_len;

	if (*n == '\0')
		return (1);
	n_len = ft_strlen(n);
	while (*h != '\0' && n_len > 0)
	{
		if (ft_strncmp(h, n, n_len) == 0 && *h == *n)
			return (0);
		h++;
		n_len--;
	}
	return (1);
}

int	ft_is_rect_helper(t_map *map)
{
	int	x;
	int	i;

	i = map->width;
	x = 2;
	if (map->str_map[i] != '\n')
		return (1);
	while (x < map->height)
	{
		if (map->str_map[(x * i) + x - 1] != '\n')
			return (1);
		x++;
	}
	if (((map->width * map->height) + map->height)
		!= ft_strlen(map->str_map) + 1)
		return (1);
	return (0);
}

/*
width started at 1 to account for '\0' and '\n'?
ft_printf("height is %d\n width is %d\n", map->height, map->width);
*/
int	ft_is_rect(t_map *map)
{
	int	i;

	i = ft_strlen(map->str_map);
	while (i > 0)
	{
		if (map->str_map[i] == '\n')
			map->height++;
		i--;
	}
	i = 0;
	while (map->str_map[i] != '\n')
	{
		map->width++;
		i++;
	}
	ft_valid_wall(map);
	map->height = map->height + 1;
	if (ft_is_rect_helper(map) == 1)
		return (1);
	return (0);
}
