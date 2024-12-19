/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:19:01 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/19 10:32:31 by shmoreno         ###   ########.fr       */
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
	deltax = x - game->mid_x;
	if (deltax != 0)
	{
		angle = deltax * game->ply->sensitivity;
		rotate_player(game, angle);
		mlx_mouse_move(game->p_mlx_init, game->p_mlx_window,
			game->mid_x, game->mid_y);
	}
	return (0);
}
