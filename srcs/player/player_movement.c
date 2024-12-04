/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:18:33 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/04 15:58:12 by tmoeller         ###   ########.fr       */
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
