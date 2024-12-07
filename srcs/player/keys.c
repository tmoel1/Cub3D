/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:07:41 by tmoeller          #+#    #+#             */
/*   Updated: 2024/12/07 17:09:02 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//from Andy

//new
int	key_press(int keycode, void *param)
{
	t_game *game = (t_game *)param;

	if (keycode == KEY_ESC)
		ft_destroy_cross(game);
	else if (keycode == KEY_W)
		game->ply->w = true;
	else if (keycode == KEY_S)
		game->ply->s = true;
	else if (keycode == KEY_A)
		game->ply->a = true;
	else if (keycode == KEY_D)
		game->ply->d = true;
	else if (keycode == KEY_ARROW_LEFT)
		game->ply->left = true;
	else if (keycode == KEY_ARROW_RIGHT)
		game->ply->right = true;
	return (0);
}

//new
int	key_release(int keycode, void *param)
{
	t_game *game = (t_game *)param;

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
