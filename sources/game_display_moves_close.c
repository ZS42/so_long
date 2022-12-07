/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display_moves_close.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:10:06 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/23 14:25:55 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
 Put a string in the window.
int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
		`int color, char *string);
 @param	void *mlx_ptr	the mlx instance;
 @param	int  x			the x location;
 @param	int  y			the y location;
 @param	int  color		the font color;
 @param	char *string	the text to write;
 @return	int				has no return value (bc).
0xTTRRGGBB T = transparency, R = red, G = green, B = blue
red	0x00FF0000
green	0x0000FF00
blue	0x000000FF
*/
void	ft_display_moves(t_game *game)
{
	char	*str;

	str = ft_itoa(game->count_steps);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_w, 2, 20);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 23, 40, 0x000000FF, "Moves");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 50, 60, 0x000000FF, str);
	free (str);
}

/*
 Destroy a window instance.
	int		mlx_destroy_window(void *mlx_ptr, void *win_ptr);
 @param	void *mlx_ptr	the mlx instance;
 @param	void *win_ptr	the window instance;
 @return	int				has no return value (bc).
*/
int	ft_close(t_game *game)
{
	mlx_destroy_window((game)->mlx_ptr, (game)->win_ptr);
	free(game->map->str_map);
	exit(0);
}
