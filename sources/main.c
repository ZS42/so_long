/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:09:33 by zsyyida           #+#    #+#             */
/*   Updated: 2022/11/22 14:30:32 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_buff_size(char **argv)
{
	int		i;
	int		fd;
	char	buff;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("error\n not a file");
		exit (0);
	}
	while (read(fd, &buff, 1))
		i++;
	close(fd);
	return (i);
}

void	read_map(char **argv, t_map	*map)
{
	int		j;
	int		fd;
	char	buff;
	int		str_size;
	char	*str_map;

	j = 0;
	str_size = ft_buff_size(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("error\n not a file");
		exit (0);
	}
	str_map = (char *) malloc(sizeof(char) * (str_size + 1));
	if (!str_map)
		return ;
	while (read(fd, &buff, 1))
	{
		str_map[j++] = buff;
	}
	str_map[j] = '\0';
	map->str_map = str_map;
	close(fd);
	error_check_helper(map);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	map = (t_map){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, NULL};
	game = (t_game){NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0};
	error_check(argc, argv, map);
	read_map(argv, &map);
	init_game(&game, &map);
	return (0);
}
