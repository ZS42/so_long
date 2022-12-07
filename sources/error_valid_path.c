/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:32:21 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/21 19:15:44 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_valid_path_visit(t_queue *ptr, t_map *map, int position)
{
	if (map->str_map[position] == '1' || map->str[position] == 'V')
		return ;
	if (map->str_map[position] == '0' || map->str_map[position] == 'C'
		|| map->str_map[position] == 'E')
	{
		if (map->str_map[position] == 'E')
			map->exit++;
		if (map->str_map[position] == 'C')
			map->collectible++;
		if (map->str_map[position] == 'P')
			map->player_count++;
		ft_lstadd_back_dl(&ptr, ft_lstnew_dl(position));
		map->str[position] = 'V';
	}
}

void	ft_valid_path_helper(t_queue *ptr, t_map *map)
{
	map->str[map->player] = 'V';
	map->player_update = ptr->content;
	ft_valid_path_visit(ptr, map, (map->player_update + 1));
	ft_valid_path_visit(ptr, map, (map->player_update - 1));
	ft_valid_path_visit(ptr, map, (map->player_update - map->width - 1));
	ft_valid_path_visit(ptr, map, (map->player_update + map->width + 1));
}

void	ft_valid_path(t_map map)
{
	t_queue	*enqueue;
	int		i;
	t_queue	*ptr;

	i = 0;
	map.str = strdup((char *)map.str_map);
	enqueue = ft_lstnew_dl(map.player);
	ptr = enqueue;
	while (enqueue != NULL)
	{
		ft_valid_path_helper(ptr, &map);
		ptr = ptr->next;
		ft_dequeue(enqueue);
		enqueue = ptr;
	}
	while (map.str[i++])
	{
		if (map.str[i] == 'C' || map.str[i] == 'E'
			|| map.count_c != map.collectible)
		{
			perror("Error\n Path is not valid");
			free (map.str);
			exit (0);
		}
	}
}
