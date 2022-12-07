/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_open_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:15:29 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/23 14:23:41 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
must use double pointer or seg faults
*/
int	ft_animate(t_game **game)
{
	int	x;
	int	y;
	int	i;

	i = (*game)->map->player;
	x = (i % ((*game)->map->width + 1)) * SIZE;
	y = find_y((*game), i) * SIZE;
	if ((*game)->count_steps % 2 == 0)
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->img_p1, x, y);
	else
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->img_p2, x, y);
	return (0);
}

void	ft_animate_enemy_helper(t_game **game, int i, int x, int y)
{
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->img_i, x, y);
	if ((*game)->map->player == i - 1)
	{
		(*game)->flag = 1;
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->img_d, x, y);
		mlx_string_put((*game)->mlx_ptr, (*game)->win_ptr, 100, 300,
			0x00FF5F1F, "You lose");
	}
}

void	ft_animate_enemy(t_game **game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while ((*game)->map->str_map[i++] != 'D')
	x = (i % ((*game)->map->width + 1)) * SIZE;
	y = find_y((*game), i) * SIZE;
	if ((*game)->count_steps % 5 == 0)
	{
		ft_animate_enemy_helper(game, i, x, y);
	}
	else if (((*game)->map->player == i - 1) && (*game)->count_steps % 5 != 0)
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->img_p1, x, y);
	else
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->img_b, x, y);
}

/*
0 is at left goes right positive
0 is at top and goes down positive
add 1 to account for new line
*/
int	find_y(t_game *game, int i)
{
	int	y;

	if (i < game->map->width +1)
		y = 0;
	else
		y = i / (game->map->width + 1);
	return (y);
}

/*
 Put an image to the given window.
 int		mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
	void *img_ptr, int x, int y);
 @param	void *mlx_ptr	the mlx instance;
 @param	void *win_ptr	the window instance;
 @param	int  x			the x location of where the image ought to be placed;
 @param	int  y			the y location of where the image ought to be placed;
 @return	int				has no return value (bc).
 have to multiply by size or else x and y are so small
 bc in pixels that appears
 as if all tiles are on top of each other
used i = -1 so could use ++i and ake function 25 lines
*/
void	open_map(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (game->map->str_map[++i])
	{
		x = (i % (game->map->width + 1)) * SIZE;
		y = find_y(game, i) * SIZE;
		if (game->map->str_map[i] == 'C')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_c, x, y);
		else if (game->map->str_map[i] == 'E')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_e1, x, y);
		else if (game->map->str_map[i] == 'P')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_p1, x, y);
		else if (game->map->str_map[i] == '0' || game->map->str_map[i] == 'D')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_b, x, y);
		else if (game->map->str_map[i] == '1')
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img_w, x, y);
	}
}
