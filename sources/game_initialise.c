/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:35:33 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/21 18:48:39 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* dont pass actual width and height just an address for them
*to be stored in for mlx_xpm_file_to_image
Convert an xpm file to a new image instance.
void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
	int *width, int *height);
@param	void *mlx_ptr	the mlx instance;
@param	char *filename	the file to load;
@param	int  *width		a pointer to where the width ought to be written;
@param	int  *height	a pointer to where the height ought to be written;
since tile is a square can use same size for width and height
 @return	void*			the image instance, and NULL in case of error.
*/

void	init_game_helper(t_game *game)
{
	int	size;

	size = SIZE;
	game->img_b = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/tile.xpm", &size, &size);
	game->img_p1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/player1.xpm", &size, &size);
	game->img_p2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/player2.xpm", &size, &size);
	game->img_c = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/collectible.xpm", &size, &size);
	game->img_e1 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/exit1.xpm", &size, &size);
	game->img_e2 = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/exit2.xpm", &size, &size);
	game->img_w = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/wall.xpm", &size, &size);
	game->img_i = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/enemy_iron.xpm", &size, &size);
	game->img_d = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/dead.xpm", &size, &size);
}

/* call the mlx_new_window function, which will return a pointer to the
window we have just created. We can give the window height, width and
a title. This width and height is in pixels so multiplying by SIZE
We then will have to call mlx_loop to initiate the window rendering.
to initiate a loop  we need mlx_loop
this is an infinite loop which never returns
to stop the program it waits for esc key to be pressed or event 17
we dont need to free memeory here as the loop never returns

Before we can do anything with the MiniLibX library we must include the
<mlx.h>header to access all the functions and we should execute the
mlx_init function. This will establish a connection to the correct
 graphical system and will return a void * which holds the location
 of our current MLX instance.

 Hook into key events with mlx_key_hook
 @param	void *win_ptr	the window instance;
 @param	int  (*f)()		the handler function, will be called as follows:
							(*f)(int key_code, void *param);
 @param	void *param		the parameter to give on each event;
 @return	int				has no return value (bc).

 Loop over the given mlx pointer.
 int	mlx_loop(game->mlx);
 @param	void *mlx_ptr	the mlx instance;
 @return	int				has no return value (bc).

 Hook into each loop.
 int	mlx_loop_hook(void *mlx_ptr, int (*f)(), void *param);
 @param	void *mlx_ptr	the mlx instance;
 @param	int  (*f)()		the handler function, will be called as follows:
							(*f)(void *param);
 @param	void *param		the parameter to give on each event;
 @return	int				has no return value (bc).

void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask,
	 int (*funct_ptr)(), void *param)
17 is on_destroy event, which means ft_close is called when
  we press the close button
One X11 event is DestroyNotify represented by key 17
one mask is (1L<<17)	StructureNotifyMask
One X11 event is key down represented by key 2
one mask is (1L<<0)	KeyPressMask
this is used if you want smooth movement and not step by step

to find keycode for whichever key you need
mlx_hook(structure_name, keycode, 1L<<0, function_to_print_keycode,
	&structure_name);
*/

void	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, (map->width * SIZE),
			(map->height * SIZE), "so_long");
	init_game_helper(game);
	open_map(game);
	mlx_key_hook(game->win_ptr, ft_movement, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, ft_close, game);
	mlx_loop(game->mlx_ptr);
	return ;
}

void	ft_exit(t_game *game, int i)
{
	int	x;
	int	y;

	game->flag = 1;
	i = game->map->player;
	x = (game->map->player % (game->map->width + 1)) * SIZE;
	y = find_y(game, i) * SIZE;
	if (game->count_c == game->map->count_c)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img_e2, x, y);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 300, 200, 0x00FF0000,
			"YOU WIN BLOOD!!!");
	}
}

/* change to print new image on top after updating x and y
	ft_printf("keycode = %d\n", key_code);
 do not use else if or game stops
*/
int	ft_movement(int key_code, t_game *game)
{
	int	i;

	i = 0;
	if (key_code == ESC)
		ft_close(game);
	if (game->flag == 1)
		return (1);
	if (game->map->str_map[game->map->player] == 'E')
		ft_exit(game, i);
	if (key_code == LEFT_KEY || key_code == A_KEY)
		ft_move_left(game, i);
	if (key_code == RIGHT_KEY || key_code == D_KEY)
		ft_move_right(game, i);
	if (key_code == UP_KEY || key_code == W_KEY)
		ft_move_up(game, i);
	if (key_code == DOWN_KEY || key_code == S_KEY)
		ft_move_down(game, i);
	return (0);
}
