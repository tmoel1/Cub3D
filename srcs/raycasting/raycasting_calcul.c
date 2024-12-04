/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:31:37 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/04 15:12:20 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	process_dda(t_game *game)
{
	while (game->ray->hit == 0)
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
		if (game->map->map[game->ray->mapy][game->ray->mapx] == '1')
		{
			game->ray->hit = 1;
			if (game->ray->side == 0)
				game->ray->perpwalldist = (game->ray->sidedistx - \
				game->ray->deltadistx);
			else
				game->ray->perpwalldist = (game->ray->sidedisty - \
				game->ray->deltadisty);
		}
	}
}
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
	game->ply->move_speed = game->ply->frame_time * 5.0; //chiffres  exactes a definir
	game->ply->rotate_speed = game->ply->frame_time * 3.0; //pareil
}
