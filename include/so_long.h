/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:00:51 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/23 14:59:12 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../minilibx_opengl_20191021/mlx_int.h"
# include "../mlx/mlx.h"
# include "../libft/include/libft.h"
# include <stdlib.h> // to use exit
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

// from KEYCODES minilibx for ASDW and keycode for arrow keys
# define LEFT_KEY				123
# define RIGHT_KEY				124
# define UP_KEY					126
# define DOWN_KEY				125
# define A_KEY					0
# define S_KEY					1
# define D_KEY					2
# define W_KEY					13
# define ESC 					53
# define SIZE					100
# define GL_SILENCE_DEPRECATION

typedef struct s_queue
{
	char			content;
	struct s_queue	*next;
	struct s_queue	*prev;
}	t_queue;

typedef struct s_map
{
	int			player;
	int			player_update;
	int			width;
	int			height;
	int			count_c;
	int			collectible;
	int			count_e;
	int			exit;
	int			count_p;
	int			player_count;
	char		*str_map;
	char		*str;
	char		**map;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_p1;
	void	*img_p2;
	void	*img_c;
	void	*img_e1;
	void	*img_e2;
	void	*img_w;
	void	*img_b;
	void	*img_d;
	void	*img_i;
	t_map	*map;
	int		count_c;
	int		count_steps;
	int		flag;
}	t_game;

/*********************************error*********************************/

void	error_check(int argc, char **argv, t_map a);
int		ft_strstr(char *h, char *n);
int		ft_buff_size(char **argv);
void	error_check_helper(t_map *map);
int		ft_is_ber(char *argv[1]);
void	error(t_map *map);
int		ft_check_char(t_map *map);
void	read_map(char **argv, t_map *map);
int		ft_is_rect(t_map *map);
void	ft_valid_char(t_map map);
void	error_message(t_map *map);
void	ft_valid_wall(t_map *map);
void	ft_valid_wall_helper(t_map *map, int w, int h);
void	ft_valid_path(t_map map);
void	ft_valid_path_helper(t_queue *enqueue, t_map *map);
void	ft_valid_path_checker(t_map *map, char *str);
void	ft_valid_path_visit(t_queue *enqueue, t_map *map, int position);

/*********************************queue*********************************/

void	*ft_dequeue(t_queue *queue);
t_queue	*ft_lstnew_dl(int content);
t_queue	*ft_lstadd_back_dl(t_queue **enqueue, t_queue *new);

/*********************************game*********************************/

void	init_game(t_game *game, t_map *map);
void	init_game_helper(t_game *game);
void	open_map(t_game *game);
int		ft_animate(t_game **game);
void	ft_animate_enemy(t_game **game);
void	ft_animate_enemy_helper(t_game **game, int i, int x, int y);
int		print_keycode(int keycode, t_game *game);
int		ft_movement(int key_code, t_game *game);
int		find_y(t_game *game, int i);
void	ft_move_left(t_game *game, int i);
void	ft_move_right(t_game *game, int i);
void	ft_move_up(t_game *game, int i);
void	ft_move_down(t_game *game, int i);
void	ft_display_moves(t_game *game);
void	ft_exit(t_game *game, int i);
int		ft_close(t_game *game);

#endif
