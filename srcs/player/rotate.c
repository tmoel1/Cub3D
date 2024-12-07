/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:06:59 by tmoeller          #+#    #+#             */
/*   Updated: 2024/12/07 21:44:34 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// from Andy

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

void	rotate_player(t_game *game, double angle)					// A AJOUTER
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

int	mouse_move(int x, int y, void *param)					// A AJOUTER
{
	t_game	*game;
	int		deltax;
	double	angle;

	(void)y;
	game = (t_game *)param;
	deltax = x - MID_X;
	if (deltax != 0)
	{
		angle = deltax * game->ply->sensitivity;
		rotate_player(game, angle);
		mlx_mouse_move(game->p_mlx_init, game->p_mlx_window, MID_X, MID_Y);
	}
	return (0);
}
