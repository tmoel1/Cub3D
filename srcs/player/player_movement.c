/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:59:05 by tmoeller          #+#    #+#             */
/*   Updated: 2024/12/09 17:01:36 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#define COLLISION_BUFFER 0.2

/*
void	move_forward(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->ply->pos_y);
	x = (int)(game->ply->pos_x + game->ply->dir_x * (game->ply->move_speed + COLLISION_BUFFER));

	if (game->map->map[y][x] != '1')
		game->ply->pos_x += game->ply->dir_x * game->ply->move_speed;

	y = (int)(game->ply->pos_y + game->ply->dir_y * (game->ply->move_speed + COLLISION_BUFFER));
	x = (int)(game->ply->pos_x);

	if (game->map->map[y][x] != '1')
		game->ply->pos_y += game->ply->dir_y * game->ply->move_speed;
}

void	move_backwards(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->ply->pos_y);
	x = (int)(game->ply->pos_x - game->ply->dir_x * (game->ply->move_speed + COLLISION_BUFFER));

	if (game->map->map[y][x] != '1')
		game->ply->pos_x -= game->ply->dir_x * game->ply->move_speed;

	y = (int)(game->ply->pos_y - game->ply->dir_y * (game->ply->move_speed + COLLISION_BUFFER));
	x = (int)(game->ply->pos_x);

	if (game->map->map[y][x] != '1')
		game->ply->pos_y -= game->ply->dir_y * game->ply->move_speed;
}

void	move_left(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->ply->pos_y);
	x = (int)(game->ply->pos_x + game->ply->dir_y * (game->ply->move_speed + COLLISION_BUFFER));

	if (game->map->map[y][x] != '1')
		game->ply->pos_x += game->ply->dir_y * game->ply->move_speed;

	y = (int)(game->ply->pos_y - game->ply->dir_x * (game->ply->move_speed + COLLISION_BUFFER));
	x = (int)(game->ply->pos_x);

	if (game->map->map[y][x] != '1')
		game->ply->pos_y -= game->ply->dir_x * game->ply->move_speed;
}

void	move_right(t_game *game)
{
	int	y;
	int	x;

	y = (int)(game->ply->pos_y);
	x = (int)(game->ply->pos_x - game->ply->dir_y * (game->ply->move_speed + COLLISION_BUFFER));

	if (game->map->map[y][x] != '1')
		game->ply->pos_x -= game->ply->dir_y * game->ply->move_speed;

	y = (int)(game->ply->pos_y + game->ply->dir_x * (game->ply->move_speed + COLLISION_BUFFER));
	x = (int)(game->ply->pos_x);

	if (game->map->map[y][x] != '1')
		game->ply->pos_y += game->ply->dir_x * game->ply->move_speed;
}
*/

void	move_forward(t_game *game)
{
	// Next intended positions with collision buffer
	double next_x;
	double next_y;
	int map_height;
	int check_x;
	int check_y;
	int row_length;

	next_x = game->ply->pos_x + game->ply->dir_x * (game->ply->move_speed + COLLISION_BUFFER);
	next_y = game->ply->pos_y + game->ply->dir_y * (game->ply->move_speed + COLLISION_BUFFER);
	map_height = ft_count_index(game->map->map);
	check_x = (int)floor(next_x);
	check_y = (int)floor(game->ply->pos_y); // current y line
	// Check horizontal (X) movement:
	if (check_y >= 0 && check_y < map_height && game->map->map[check_y] != NULL)
	{
		row_length = (int)ft_strlen(game->map->map[check_y]);
		if (check_x >= 0 && check_x < row_length && game->map->map[check_y][check_x] != '1')
		{
			// Safe to move in x-direction
			game->ply->pos_x += game->ply->dir_x * game->ply->move_speed;
		}
	}
	// Check vertical (Y) movement:
	check_x = (int)floor(game->ply->pos_x); // potentially updated x
	check_y = (int)floor(next_y);
	if (check_y >= 0 && check_y < map_height && game->map->map[check_y] != NULL)
	{
		row_length = (int)ft_strlen(game->map->map[check_y]);
		if (check_x >= 0 && check_x < row_length && game->map->map[check_y][check_x] != '1')
		{
			// Safe to move in y-direction
			game->ply->pos_y += game->ply->dir_y * game->ply->move_speed;
		}
	}
}

void	move_backwards(t_game *game)
{
	double next_x;
	double next_y;
	// !!!!!!!!!! in fact these variables should proabbly go in a struct somewhere to avoid declaring??
	next_x = game->ply->pos_x - game->ply->dir_x * (game->ply->move_speed + COLLISION_BUFFER);
	next_y = game->ply->pos_y - game->ply->dir_y * (game->ply->move_speed + COLLISION_BUFFER);
	int map_height = ft_count_index(game->map->map);

	// Check horizontal (X) movement
	int check_y = (int)floor(game->ply->pos_y);
	int check_x = (int)floor(next_x);
	if (check_y >= 0 && check_y < map_height && game->map->map[check_y] != NULL)
	{
		int row_length = (int)ft_strlen(game->map->map[check_y]);
		if (check_x >= 0 && check_x < row_length && game->map->map[check_y][check_x] != '1')
			game->ply->pos_x -= game->ply->dir_x * game->ply->move_speed;
	}

	// Check vertical (Y) movement
	check_x = (int)floor(game->ply->pos_x);
	check_y = (int)floor(next_y);
	if (check_y >= 0 && check_y < map_height && game->map->map[check_y] != NULL)
	{
		int row_length = (int)ft_strlen(game->map->map[check_y]);
		if (check_x >= 0 && check_x < row_length && game->map->map[check_y][check_x] != '1')
			game->ply->pos_y -= game->ply->dir_y * game->ply->move_speed;
	}
}

void	move_left(t_game *game)
{
	// For moving left: we move perpendicular to dir_x/dir_y
	// left direction: +dir_y on X axis, -dir_x on Y axis
	double next_x;
	double next_y;
	// !!!!!!! same as above maybe
	next_x = game->ply->pos_x + game->ply->dir_y * (game->ply->move_speed + COLLISION_BUFFER);
	next_y = game->ply->pos_y - game->ply->dir_x * (game->ply->move_speed + COLLISION_BUFFER);
	int map_height = ft_count_index(game->map->map);

	// Check horizontal (X) movement
	int check_y = (int)floor(game->ply->pos_y);
	int check_x = (int)floor(next_x);
	if (check_y >= 0 && check_y < map_height && game->map->map[check_y] != NULL)
	{
		int row_length = (int)ft_strlen(game->map->map[check_y]);
		if (check_x >= 0 && check_x < row_length && game->map->map[check_y][check_x] != '1')
			game->ply->pos_x += game->ply->dir_y * game->ply->move_speed;
	}

	// Check vertical (Y) movement
	check_x = (int)floor(game->ply->pos_x);
	check_y = (int)floor(next_y);
	if (check_y >= 0 && check_y < map_height && game->map->map[check_y] != NULL)
	{
		int row_length = (int)ft_strlen(game->map->map[check_y]);
		if (check_x >= 0 && check_x < row_length && game->map->map[check_y][check_x] != '1')
			game->ply->pos_y -= game->ply->dir_x * game->ply->move_speed;
	}
}

void	move_right(t_game *game)
{
	// For moving right: we move perpendicular in the opposite direction to left
	// right direction: -dir_y on X axis, +dir_x on Y axis
	double next_x;
	double next_y;
	// !!!! same
	next_x = game->ply->pos_x - game->ply->dir_y * (game->ply->move_speed + COLLISION_BUFFER);
	next_y = game->ply->pos_y + game->ply->dir_x * (game->ply->move_speed + COLLISION_BUFFER);
	int map_height = ft_count_index(game->map->map);

	// Check horizontal (X) movement
	int check_y = (int)floor(game->ply->pos_y);
	int check_x = (int)floor(next_x);
	if (check_y >= 0 && check_y < map_height && game->map->map[check_y] != NULL)
	{
		int row_length = (int)ft_strlen(game->map->map[check_y]);
		if (check_x >= 0 && check_x < row_length && game->map->map[check_y][check_x] != '1')
			game->ply->pos_x -= game->ply->dir_y * game->ply->move_speed;
	}

	// Check vertical (Y) movement
	check_x = (int)floor(game->ply->pos_x);
	check_y = (int)floor(next_y);
	if (check_y >= 0 && check_y < map_height && game->map->map[check_y] != NULL)
	{
		int row_length = (int)ft_strlen(game->map->map[check_y]);
		if (check_x >= 0 && check_x < row_length && game->map->map[check_y][check_x] != '1')
			game->ply->pos_y += game->ply->dir_x * game->ply->move_speed;
	}
}
