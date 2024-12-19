/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:18:24 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/19 14:08:20 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void cleanup_and_exit(t_game *game)
{
    int i;

    // Destroy textures/images if you loaded any
    if (game->textures.north.i)
        mlx_destroy_image(game->p_mlx_init, game->textures.north.i);
    if (game->textures.south.i)
        mlx_destroy_image(game->p_mlx_init, game->textures.south.i);
    if (game->textures.east.i)
        mlx_destroy_image(game->p_mlx_init, game->textures.east.i);
    if (game->textures.west.i)
        mlx_destroy_image(game->p_mlx_init, game->textures.west.i);

    // Destroy the main image if it exists
    if (game->img.i)
        mlx_destroy_image(game->p_mlx_init, game->img.i);

    // Destroy the window
    if (game->p_mlx_window)
	{
		printf("HEREREREE");
        mlx_destroy_window(game->p_mlx_init, game->p_mlx_window);
		if (game->p_mlx_init)
			mlx_destroy_display(game->p_mlx_init);
		free(game->p_mlx_init);
	}

	

    // Free map lines
    if (game->map->map)
    {
        for (i = 0; game->map->map[i]; i++)
            free(game->map->map[i]);
        free(game->map->map);
    }

    // Free directions
    if (game->map->dir)
    {
        for (i = 0; i < 6; i++)
        {
            if (game->map->dir[i])
                free(game->map->dir[i]);
        }
        free(game->map->dir);
    }
/*
    // Free any other allocated strings
    if (game->map->line)
        free(game->map->line);
    if (game->map->tmp)
        free(game->map->tmp);
*/
    // Finally exit
    exit(EXIT_SUCCESS);
}


// Function to quit the game when the ESC key is pressed
int	ft_destroy_escape(int keysim, t_game *game)
{
	if (keysim == KEY_ESC)
	{
		printf("ZZZZZZZZZZZZZZ");
		//mlx_destroy_window(game->p_mlx_init, game->p_mlx_window);
		//game->p_mlx_window = NULL;
		cleanup_and_exit(game);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

// Function to quit the game when the red cross is pressed
int	ft_destroy_cross(t_game *game)
{
	//mlx_destroy_window(game->p_mlx_init, game->p_mlx_window);
	//game->p_mlx_window = NULL;
	cleanup_and_exit(game); //ADDED
	exit(EXIT_SUCCESS);
	return (0);
}

/*int	ft_resize_window(t_map *map)
{
	return (0);
}*/
