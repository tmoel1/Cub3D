/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:06:59 by tmoeller          #+#    #+#             */
/*   Updated: 2024/12/19 12:56:46 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ply->dir_x;
	game->ply->dir_x = game->ply->dir_x * cos(game->ply->rotate_speed)
		- game->ply->dir_y * sin(game->ply->rotate_speed);
	game->ply->dir_y = old_dir_x * sin(game->ply->rotate_speed)
		+ game->ply->dir_y * cos(game->ply->rotate_speed);
	old_plane_x = game->ply->plane_x;
	game->ply->plane_x = game->ply->plane_x * cos(game->ply->rotate_speed)
		- game->ply->plane_y * sin(game->ply->rotate_speed);
	game->ply->plane_y = old_plane_x * sin(game->ply->rotate_speed)
		+ game->ply->plane_y * cos(game->ply->rotate_speed);
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ply->dir_x;
	game->ply->dir_x = game->ply->dir_x * cos(-game->ply->rotate_speed)
		- game->ply->dir_y * sin(-game->ply->rotate_speed);
	game->ply->dir_y = old_dir_x * sin(-game->ply->rotate_speed)
		+ game->ply->dir_y * cos(-game->ply->rotate_speed);
	old_plane_x = game->ply->plane_x;
	game->ply->plane_x = game->ply->plane_x * cos(-game->ply->rotate_speed)
		- game->ply->plane_y * sin(-game->ply->rotate_speed);
	game->ply->plane_y = old_plane_x * sin(-game->ply->rotate_speed)
		+ game->ply->plane_y * cos(-game->ply->rotate_speed);
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ply->dir_x;
	game->ply->dir_x = game->ply->dir_x * cos(angle)
		- game->ply->dir_y * sin(angle);
	game->ply->dir_y = old_dir_x * sin(angle) + game->ply->dir_y * cos(angle);
	old_plane_x = game->ply->plane_x;
	game->ply->plane_x = game->ply->plane_x * cos(angle)
		- game->ply->plane_y * sin(angle);
	game->ply->plane_y = old_plane_x * sin(angle)
		+ game->ply->plane_y * cos(angle);
}
