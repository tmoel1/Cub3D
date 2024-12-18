/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:19:01 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/18 23:31:04 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_move(int x, int y, void *param)
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
