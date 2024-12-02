/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:44:51 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/02 12:16:57 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_raycast(t_game *game)
{
	game->ply->dir_x = 0.0;
	game->ply->dir_y = 0.0;
	game->ply->plane_x = 0.0;
	game->ply->plane_y = 0.0;
	game->ray->raydirx = 0.0;
	game->ray->raydiry = 0.0;
	game->ray->sidedistx = 0.0;
	game->ray->sidedisty = 0.0;
	game->ray->x = 0;
	game->ray->mapx = 0;
	game->ray->mapy = 0;
	game->ray->hit = 0;
	game->ray->side = 0;
	game->ray->perpwalldist = 0.0;
}

void	ft_init(t_game *game)
{
	game->ray->camerax = 2 * game->ray->x / (double)WIN_WIDTH - 1;
}

void	ft_dda_algo(t_game *game)
{
	game->ray->mapx = (int)game->ply->pos_x;
	game->ray->mapy = (int)game->ply->pos_x;
	game->ray->raydirx = game->ply->dir_x + \
		game->ply->plane_x * game->ray->camerax;
	game->ray->raydiry = game->ply->dir_y + \
		game->ply->plane_y * game->ray->camerax;
	init_deltadist(game);
	set_step(game);
}

static void	init_deltadist(t_game *game)
{
	if (game->ray->raydiry == 0)
	{
		game->ray->deltadistx = 0;
	}
	else
	{
		if (game->ray->raydirx == 0)
			game->ray->deltadistx = 1;
		else
			game->ray->deltadistx = fabs(1 / game->ray->raydirx);
	}
	if (game->ray->raydirx == 0)
	{
		game->ray->deltadisty = 0;
	}
	else
	{
		if (game->ray->raydiry == 0)
			game->ray->deltadisty = 1;
		else
			game->ray->deltadisty = fabs(1 / game->ray->raydiry);
	}
}

static void	set_step(t_game *game)
{
	if (game->ray->raydirx < 0)
	{
		game->ray->stepx = -1;
		game->ray->sidedistx = (game->ply->pos_x - \
			(double)game->ray->mapx) * game->ray->deltadistx;
	}
	else
	{
		game->ray->stepx = 1;
		game->ray->sidedistx = (game->ply->pos_x - \
			game->ray->mapx + 1.0) * game->ray->deltadistx;
	}
	if (game->ray->raydiry < 0)
	{
		game->ray->stepy = -1;
		game->ray->sidedisty = (game->ply->pos_y - \
			(double)game->ray->mapy) * game->ray->deltadisty;
	}
	else
	{
		game->ray->stepy = 1;
		game->ray->sidedisty = (game->ply->pos_y - \
			game->ray->mapy + 1.0) * game->ray->deltadisty;
	}
}
