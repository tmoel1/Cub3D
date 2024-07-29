/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:18:24 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/28 13:02:38 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Function to quit the game when the ESC key is pressed
int	ft_destroy_escape(int keysim, t_game *game)
{
	if (keysim == KEY_ESC)
	{
		mlx_destroy_window(game->p_mlx_init, game->p_mlx_window);
		game->p_mlx_window = NULL;
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// Function to quit the game when the red cross is pressed
int	ft_destroy_cross(t_game *game)
{
	mlx_destroy_window(game->p_mlx_init, game->p_mlx_window);
	game->p_mlx_window = NULL;
	exit(EXIT_SUCCESS);
	return (0);
}

/*int	ft_resize_window(t_map *map)
{
	return (0);
}*/
