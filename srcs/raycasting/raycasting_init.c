/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:44:51 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/07 23:06:02 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void ft_init_raycast(t_game *game)
{
	double rad_angle = game->ply->dir_angle * (M_PI / 180.0);
	game->ply->dir_x = cos(rad_angle);
	game->ply->dir_y = sin(rad_angle);
	game->ply->plane_x = -0.66 * sin(rad_angle);
	game->ply->plane_y = 0.66 * cos(rad_angle);
	game->ray->x = 0;
	game->ray->hit = 0;
	game->ray->side = 0;
	game->ray->mapx = 0;
	game->ray->mapy = 0;
	game->ray->stepx = 0;
	game->ray->stepy = 0;
	game->ray->sidedistx = 0.0;
	game->ray->sidedisty = 0.0;
	game->ray->deltadistx = 0.0;
	game->ray->deltadisty = 0.0;
	game->ray->perpwalldist = 0.0;
	game->ray->line_height = 0;
	game->ray->draw_start = 0;
	game->ray->draw_end = 0;
	game->ray->color = 0;
}

// rad_angle is converted from degrees to radians using Pi / 180
// direction vectors and camera plane uses trig functions cos & sin
// 0.66 is a standard viewing angle

static void init_deltadist(t_game *game)
{
	if (game->ray->raydirx == 0)
		game->ray->deltadistx = 1e30;
	else
		game->ray->deltadistx = fabs(1 / game->ray->raydirx);
	if (game->ray->raydiry == 0)
		game->ray->deltadisty = 1e30;
	else
		game->ray->deltadisty = fabs(1 / game->ray->raydiry);
}

// to calculate distance ray must travel (deltadist), necessary for DDA algo
// distance being one x or y side to the next within the grid map
// (all as seen from above)
// 1e30 is just a generic "very large number" to prevent division by 0
// fabs() computes the absolute value of a float aka ensures it's positive

static void set_step(t_game *game)
{
	if (game->ray->raydirx < 0)
	{
		game->ray->stepx = -1;
		game->ray->sidedistx = (game->ply->pos_x - game->ray->mapx) * game->ray->deltadistx;
	}
	else
	{
		game->ray->stepx = 1;
		game->ray->sidedistx = (game->ray->mapx + 1.0 - game->ply->pos_x) * game->ray->deltadistx;
	}
	if (game->ray->raydiry < 0)
	{
		game->ray->stepy = -1;
		game->ray->sidedisty = (game->ply->pos_y - game->ray->mapy) * game->ray->deltadisty;
	}
	else
	{
		game->ray->stepy = 1;
		game->ray->sidedisty = (game->ray->mapy + 1.0 - game->ply->pos_y) * game->ray->deltadisty;
	}
}

// sets "step" distance which is the initial distance the rays will travel
// to reach the first vertical or horizontal gridline (from above)
// used later for calculating wall intersections
// -1 and +1 here represent for x & y left/right and up/down respectively

void	ft_init(t_game *game)
{
	game->ray->camerax = 2 * game->ray->x / (double)WIN_WIDTH - 1;
	game->ray->raydirx = game->ply->dir_x + game->ply->plane_x * game->ray->camerax;
	game->ray->raydiry = game->ply->dir_y + game->ply->plane_y * game->ray->camerax;
	game->ray->mapx = (int)game->ply->pos_x;
	game->ray->mapy = (int)game->ply->pos_y;
	game->ray->hit = 0;
}

// for intial params of each vertical ray
// camera x coords are -1 to +1, determines ray position on camera plane
// ray direction vectors combine player's position and camera plane vector
// casting player grid position to (int) is for DDA algo

void	ft_dda_algo(t_game *game)
{
	init_deltadist(game);
	set_step(game);
}

// "Digital Differential Analysis"
// algo styled from <lodev.org> raycasting tutorial
// it's basically magic
// or just a series of math functions if you remember highschool trigonometry
// so, magic.
// calculates angles/paths and incremental distances for stepping through 
// the 2D grid map (the "3D" map as seen from above)