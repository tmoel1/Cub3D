#include "../../includes/cub3d.h"

#define COLLISION_BUFFER 0.2

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
