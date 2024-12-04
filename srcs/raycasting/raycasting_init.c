/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:44:51 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/04 15:59:51 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//new
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

//new
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

//new
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

//new
void	ft_init(t_game *game)
{
	game->ray->camerax = 2 * game->ray->x / (double)WIN_WIDTH - 1;
	game->ray->raydirx = game->ply->dir_x + game->ply->plane_x * game->ray->camerax;
	game->ray->raydiry = game->ply->dir_y + game->ply->plane_y * game->ray->camerax;
	game->ray->mapx = (int)game->ply->pos_x;
	game->ray->mapy = (int)game->ply->pos_y;
	game->ray->hit = 0;
}

//new
void	ft_dda_algo(t_game *game)
{
	init_deltadist(game);
	set_step(game);
}
