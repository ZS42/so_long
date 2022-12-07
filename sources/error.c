/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:59:57 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/22 14:38:05 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <errno.h>
/*
#include <stdio.h>
#include <string.h>

check for .ber
check for rectangle
check for valid path
check for valid wall
check for characters for collectible, starting point, exit
*/
void	error_check(int argc, char **argv, t_map a)
{
	(void)a;
	if (argc != 2)
	{
		perror("Error\n wrong number of arguments");
		exit (0);
	}
	if (ft_is_ber(argv) == 1)
	{
		perror("Error\n require .ber argument");
		exit(0);
	}
}

void	error(t_map *map)
{
	free(map->str_map);
	exit (0);
}

void	error_check_helper(t_map *map)
{
	int	i;

	i = ft_check_char(map);
	if (i == 3)
	{
		perror("Error\n must have at least one collectable");
		error(map);
	}
	if (i == 1)
	{
		perror("Error\n wrong number of players");
		error(map);
	}
	if (i == 2)
	{
		perror("Error\n wrong number of exits");
		error(map);
	}
	if (ft_is_rect(map) == 1)
	{
		perror("Error\n Map is not a rectangle");
		error(map);
	}
	ft_valid_char(*map);
	ft_valid_path(*map);
}

int	ft_is_ber(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	if (len < 5)
		return (1);
	if (ft_strstr(argv[1], ".ber") == 0)
		return (1);
	return (0);
}

/*
member reference type 't_map' (aka 'struct s_map') is not a pointer use '.';
member reference type 't_map' (aka 'struct s_map') is a pointer use '->';
printf("map string=\n%s\n", map.str_map);
ft_printf("P is %d\n", map->count_p);
ft_printf("E is %d\n", map->count_e);
ft_printf("C is %d\n", map->count_c);
ft_printf("Player is %d\n", map->player);
*/
int	ft_check_char(t_map *map)
{
	int	j;

	j = 0;
	while (j < ft_strlen(map->str_map))
	{
		if ((map->str_map[j]) == 'C')
			map->count_c++;
		if ((map->str_map[j]) == 'P')
		{
			map->count_p++;
			map->player = j;
		}
		if ((map->str_map[j]) == 'E')
			map->count_e++;
		j++;
	}
	if (map->count_p != 1)
		return (1);
	if (map->count_e != 1)
		return (2);
	if (map->count_c < 1)
		return (3);
	return (0);
}
