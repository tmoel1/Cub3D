/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:31:37 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/09 16:51:52 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <ctype.h>

void	perp_init(t_game *game)
{
	if (game->ray->side == 0)
		game->ray->perpwalldist = (game->ray->sidedistx
			- game->ray->deltadistx);
	else
		game->ray->perpwalldist = (game->ray->sidedisty
			- game->ray->deltadisty);
}

// corrects for fisheye distortion by calculating true perpendicular distance

static int check_collision(t_game *game, int map_height)
{
	int		row_length;
	char	tile;

	if (game->ray->mapy < 0 || game->ray->mapy >= map_height)
	{
		game->ray->hit = 1;
		return 1;
	}
	if (game->map->map[game->ray->mapy] == NULL)
	{
		game->ray->hit = 1;
		return 1;
	}
	row_length = (int)ft_strlen(game->map->map[game->ray->mapy]);
	if (game->ray->mapx < 0 || game->ray->mapx >= row_length)
	{
		game->ray->hit = 1;
		return 1;
	}
	tile = game->map->map[game->ray->mapy][game->ray->mapx];
	//printf("caract: %d | mapy: %d | mapx: %d\n", tile, game->ray->mapy, game->ray->mapx); // Debug print
	// if (tile != '0' && tile != 'N' && tile != 'E' && tile != 'W')
	if (tile == '1')
		game->ray->hit = 1;
	return game->ray->hit;
}

// checks if y is out of map bounds, if so marks as hit/collision
// checks if the map row even exists as sometime it doesn't, if it does -> hit
// same out-of-bounds check for the x axis, if so the it's a hit
// tile takes the location of position the ray is touching
// if it's a wall then hit of course, then return hit to finish

static void step_ray(t_game *game)
{
	if (game->ray->sidedistx < game->ray->sidedisty)
	{
		game->ray->sidedistx += game->ray->deltadistx;
		game->ray->mapx += game->ray->stepx;
		game->ray->side = 0;
	}
	else
	{
		game->ray->sidedisty += game->ray->deltadisty;
		game->ray->mapy += game->ray->stepy;
		game->ray->side = 1;
	}
}

// chooses to step left or right
// increments axis distance, moves to next square
// sets variable to 0 or 1 depending on if it hit a vertical or horizonal wall

void process_dda(t_game *game)
{
	int map_height;

	map_height = ft_count_index(game->map->map);
	while (game->ray->hit == 0)
	{
		step_ray(game);
		if (check_collision(game, map_height))
			break;
	}
}

// traverses 2D grid map (step_ray) constantly checking until a wall is hit 
// checks also constantly for collisions due to rays touching things they shouldn't
// breaks out if so or if hit == 1

void	calculate_line_height(t_game *game)
{
	game->ray->line_height = (int)(WIN_HEIGHT / game->ray->perpwalldist);
	game->ray->draw_start = -game->ray->line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = game->ray->line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray->draw_end >= WIN_HEIGHT)
		game->ray->draw_end = WIN_HEIGHT - 1;
}

// for determining the height of the vertical slice of wall to be drawn
// basically what makes walls "further away" drawn smaller and vice versa
// if statements act as out-of-bounds checks

double	get_time(void)
{
	{
		struct timeval	time;
		gettimeofday(&time, NULL);
		return (time.tv_sec * 1000.0 + time.tv_usec / 1000.0);
	}
}

void	update_frame_time(t_game *game)
{
	game->ply->old_time = game->ply->time;
	game->ply->time = get_time();
	game->ply->frame_time = (game->ply->time - game->ply->old_time) / 1000.0;
	game->ply->move_speed = game->ply->frame_time * 5.0;
	game->ply->rotate_speed = game->ply->frame_time * 3.0;
}
//!!!!!! might look at adjusting/optimising move_speed and rotate_speed ??