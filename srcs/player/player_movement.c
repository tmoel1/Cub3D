/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:18:33 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/04 12:10:58 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//from Andy 

void	move_forward(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->ply->pos_y);
	x = (int)(game->ply->pos_x + game->ply->dir_x * game->ply->move_speed);

	if (game->map->map[y][x] != '1')
		game->ply->pos_x += game->ply->dir_x * game->ply->move_speed;

	y = (int)(game->ply->pos_y + game->ply->dir_y * game->ply->move_speed);
	x = (int)(game->ply->pos_x);

	if (game->map->map[y][x] != '1')
		game->ply->pos_y += game->ply->dir_y * game->ply->move_speed;
}

void	move_backwards(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->ply->pos_y);
	x = (int)(game->ply->pos_x - game->ply->dir_x * game->ply->move_speed);

	if (game->map->map[y][x] != '1')
		game->ply->pos_x -= game->ply->dir_x * game->ply->move_speed;

	y = (int)(game->ply->pos_y - game->ply->dir_y * game->ply->move_speed);
	x = (int)(game->ply->pos_x);

	if (game->map->map[y][x] != '1')
		game->ply->pos_y -= game->ply->dir_y * game->ply->move_speed;
}

void	move_left(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->ply->pos_y);
	x = (int)(game->ply->pos_x + game->ply->dir_y * game->ply->move_speed);

	if (game->map->map[y][x] != '1')
		game->ply->pos_x += game->ply->dir_y * game->ply->move_speed;

	y = (int)(game->ply->pos_y - game->ply->dir_x * game->ply->move_speed);
	x = (int)(game->ply->pos_x);

	if (game->map->map[y][x] != '1')
		game->ply->pos_y -= game->ply->dir_x * game->ply->move_speed;
}

void	move_right(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->ply->pos_y);
	x = (int)(game->ply->pos_x - game->ply->dir_y * game->ply->move_speed);

	if (game->map->map[y][x] != '1')
		game->ply->pos_x -= game->ply->dir_y * game->ply->move_speed;

	y = (int)(game->ply->pos_y + game->ply->dir_x * game->ply->move_speed);
	x = (int)(game->ply->pos_x);

	if (game->map->map[y][x] != '1')
		game->ply->pos_y += game->ply->dir_x * game->ply->move_speed;
}

/*
int	main(int argc, char **argv)
{
	t_game	game;

	if (ft_parse_base(&game.map, argc, argv) == 1)
		exit(EXIT_FAILURE);
	game.p_mlx_init = mlx_init();
	if (!game.p_mlx_init)
		return (EXIT_FAILURE);
	game.p_mlx_window = mlx_new_window(game.p_mlx_init, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_TITLE);
	if (!game.p_mlx_window)
	{
		return (EXIT_FAILURE);
	}
	init_player(&game);
	mlx_loop_hook(game.p_mlx_init, &ft_update_game, &game);
	mlx_hook(game.p_mlx_window, KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.p_mlx_window, KEY_RELEASE, 0, &key_release, &game);
	ft_hook(&game);
	mlx_loop(game.p_mlx_init);
	return (0);
}
*/