/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:26:06 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/18 16:29:26 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_game *game)
{
	t_move	move;

	init_move(&move, game, game->ply->dir_x, game->ply->dir_y);
	check_horizontal(&move, game, game->ply->dir_x);
	check_vertical(&move, game, game->ply->dir_y);
}

void	move_backwards(t_game *game)
{
	t_move	move;

	init_move(&move, game, -game->ply->dir_x, -game->ply->dir_y);
	check_horizontal(&move, game, -game->ply->dir_x);
	check_vertical(&move, game, -game->ply->dir_y);
}

void	move_left(t_game *game)
{
	t_move	move;

	init_move(&move, game, game->ply->dir_y, -game->ply->dir_x);
	check_horizontal(&move, game, game->ply->dir_y);
	check_vertical(&move, game, -game->ply->dir_x);
}

void	move_right(t_game *game)
{
	t_move	move;

	init_move(&move, game, -game->ply->dir_y, game->ply->dir_x);
	check_horizontal(&move, game, -game->ply->dir_y);
	check_vertical(&move, game, game->ply->dir_x);
}
