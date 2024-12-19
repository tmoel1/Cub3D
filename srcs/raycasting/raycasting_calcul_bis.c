/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcul_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:12:45 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/18 13:13:51 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// for determining the height of the vertical slice of wall to be drawn
// basically what makes walls "further away" drawn smaller and vice versa
// if statements act as out-of-bounds checks

double	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000.0 + time.tv_usec / 1000.0);
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