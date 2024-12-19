/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:18:24 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/19 14:37:29 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	finish_cleanup(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->map)
	{
		while (game->map->map[i])
		{
			free(game->map->map[i]);
			i++;
		}
		free(game->map->map);
	}
	i = 0;
	if (game->map->dir)
	{
		while (i < 6)
		{
			free(game->map->dir[i]);
			i++;
		}
		free(game->map->dir);
	}
}

static void	cleanup_and_exit(t_game *game)
{
	if (game->textures.north.i)
		mlx_destroy_image(game->p_mlx_init, game->textures.north.i);
	if (game->textures.south.i)
		mlx_destroy_image(game->p_mlx_init, game->textures.south.i);
	if (game->textures.east.i)
		mlx_destroy_image(game->p_mlx_init, game->textures.east.i);
	if (game->textures.west.i)
		mlx_destroy_image(game->p_mlx_init, game->textures.west.i);
	if (game->img.i)
		mlx_destroy_image(game->p_mlx_init, game->img.i);
	if (game->p_mlx_window)
	{
		mlx_destroy_window(game->p_mlx_init, game->p_mlx_window);
		if (game->p_mlx_init)
			mlx_destroy_display(game->p_mlx_init);
		free(game->p_mlx_init);
	}
	finish_cleanup(game);
}

// Function to quit the game when the red cross is pressed
int	ft_destroy_cross(t_game *game)
{
	cleanup_and_exit(game);
	exit(EXIT_SUCCESS);
	return (0);
}
