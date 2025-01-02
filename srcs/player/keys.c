/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:07:41 by tmoeller          #+#    #+#             */
/*   Updated: 2024/12/20 12:36:42 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_ESC)
		ft_destroy_cross(game);
	else if (keycode == KEY_W && game->b_menu)
		game->ply->w = true;
	else if (keycode == KEY_S && game->b_menu)
		game->ply->s = true;
	else if (keycode == KEY_A && game->b_menu)
		game->ply->a = true;
	else if (keycode == KEY_D && game->b_menu)
		game->ply->d = true;
	else if (keycode == KEY_ARROW_LEFT && game->b_menu)
		game->ply->left = true;
	else if (keycode == KEY_ARROW_RIGHT && game->b_menu)
		game->ply->right = true;
	else if (keycode == KEY_SPACE && !game->b_menu)
		ft_space_press(keycode, param);
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W)
		game->ply->w = false;
	else if (keycode == KEY_S)
		game->ply->s = false;
	else if (keycode == KEY_A)
		game->ply->a = false;
	else if (keycode == KEY_D)
		game->ply->d = false;
	else if (keycode == KEY_ARROW_LEFT)
		game->ply->left = false;
	else if (keycode == KEY_ARROW_RIGHT)
		game->ply->right = false;
	return (0);
}
