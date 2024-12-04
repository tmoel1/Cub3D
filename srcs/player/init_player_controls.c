/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_controls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:04:30 by tmoeller          #+#    #+#             */
/*   Updated: 2024/12/04 12:05:22 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// from Andy

void	controls(t_game *game)
{
	if (game->ply->w)
		move_forward(game);
	if (game->ply->s)
		move_backwards(game);
	if (game->ply->a)
		move_left(game);
	if (game->ply->d)
		move_right(game);
	if (game->ply->left)
		rotate_left(game);
	if (game->ply->right)
		rotate_right(game);
}

int	ft_update_game(t_game *game)
{
	controls(game);
	game->ply->frame_time = 16.0 / 1000.0;
	game->ply->move_speed = game->ply->frame_time * 5.0;
	game->ply->rotate_speed = game->ply->frame_time * 3.0;
	return (0);
}

void	init_player(t_game *game)
{
	game->ply->frame_time = 0.0;
	game->ply->move_speed = 0.0;
	game->ply->rotate_speed = 0.0;
	game->ply->plane_x = 0.66;
	game->ply->plane_y = 0.0;
	game->ply->w = false;
	game->ply->a = false;
	game->ply->s = false;
	game->ply->d = false;
	game->ply->left = false;
	game->ply->right = false;
}
