/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:53:51 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/21 17:55:30 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_left(t_game *game, int i)
{
	int	x;
	int	y;

	if ((game->map->str_map[game->map->player - 1] == '1')
		|| ((game->map->str_map[game->map->player - 1] == 'E')
			&& (game->count_c != game->map->count_c)))
		return ;
	i = game->map->player;
	x = (game->map->player % (game->map->width + 1)) * SIZE;
	y = find_y(game, i) * SIZE;
	if (game->map->str_map[game->map->player - 1] == 'C')
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 250, 0x00FF5F1F,
			"You are beating iron");
		game->count_c++;
		game->map->str_map[game->map->player - 1] = '0';
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_b, x, y);
	game->map->player = game->map->player - 1;
	ft_animate(&game);
	ft_animate_enemy(&game);
	game->count_steps += 1;
	ft_printf(" number of movements %d\n", game->count_steps);
	ft_display_moves(game);
}

void	ft_move_right(t_game *game, int i)
{
	int	x;
	int	y;

	if ((game->map->str_map[game->map->player + 1] == '1')
		|| ((game->map->str_map[game->map->player + 1] == 'E')
			&& (game->count_c != game->map->count_c)))
		return ;
	i = game->map->player;
	x = (game->map->player % (game->map->width + 1)) * SIZE;
	y = find_y(game, i) * SIZE;
	if (game->map->str_map[game->map->player + 1] == 'C')
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 250, 0x00FF5F1F,
			"You are beating iron");
		game->count_c++;
		game->map->str_map[game->map->player + 1] = '0';
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_b, x, y);
	game->map->player = game->map->player + 1;
	ft_animate(&game);
	ft_animate_enemy(&game);
	game->count_steps += 1;
	ft_printf(" number of movements %d\n", game->count_steps);
	ft_display_moves(game);
}

void	ft_move_up(t_game *game, int i)
{
	int	x;
	int	y;

	if ((game->map->str_map[game->map->player - (game->map->width + 1)] == '1')
		|| ((game->map->str_map[game->map->player - (game->map->width + 1)]
				== 'E') && (game->count_c != game->map->count_c)))
		return ;
	i = game->map->player;
	x = (game->map->player % (game->map->width + 1)) * SIZE;
	y = find_y(game, i) * SIZE;
	if (game->map->str_map[game->map->player - (game->map->width + 1)] == 'C')
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 250, 0x00FF5F1F,
			"You are beating iron");
		game->count_c++;
		game->map->str_map[game->map->player - (game->map->width + 1)] = '0';
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_b, x, y);
	game->map->player = game->map->player - game->map->width - 1;
	ft_animate(&game);
	ft_animate_enemy(&game);
	game->count_steps += 1;
	ft_printf(" number of movements %d\n", game->count_steps);
	ft_display_moves(game);
}

void	ft_move_down(t_game *game, int i)
{
	int	x;
	int	y;

	if ((game->map->str_map[game->map->player + (game->map->width + 1)] == '1')
		|| ((game->map->str_map[game->map->player + (game->map->width + 1)]
				== 'E') && (game->count_c != game->map->count_c)))
		return ;
	i = game->map->player;
	x = (game->map->player % (game->map->width + 1)) * SIZE;
	y = find_y(game, i) * SIZE;
	if (game->map->str_map[game->map->player + (game->map->width + 1)] == 'C')
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 250, 0x00FF5F1F,
			"You are beating iron");
		game->count_c++;
		game->map->str_map[game->map->player + (game->map->width + 1)] = '0';
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_b, x, y);
	game->map->player = game->map->player + game->map->width +1;
	ft_animate(&game);
	ft_animate_enemy(&game);
	game->count_steps += 1;
	ft_printf(" number of movements %d\n", game->count_steps);
	ft_display_moves(game);
}
