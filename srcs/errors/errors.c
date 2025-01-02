/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:13:02 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/21 15:07:26 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_ptr(t_game *game)
{
	if (game->map->line != NULL)
	{
		free(game->map->line);
		game->map->line = NULL;
	}
	if (game->map->dir != NULL)
	{
		free(game->map->dir);
		game->map->dir = NULL;
	}
	if (game->map->map != NULL)
	{
		free(game->map->map);
		game->map->map = NULL;
	}
}

void	ft_free_all(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->index_map)
	{
		if (game->map->map != NULL && game->map->map[i] != NULL)
		{
			free(game->map->map[i]);
			game->map->map[i] = NULL;
		}
	}
	i = -1;
	while (++i < 6)
	{
		if (game->map->dir != NULL && game->map->dir[i] != NULL)
		{
			free(game->map->dir[i]);
			game->map->dir[i] = NULL;
		}
	}
	ft_free_ptr(game);
}

void	ft_error(t_game *game, char *str, int count)
{
	printf("Error: %s: line %d\n", str, count);
	ft_free_all(game);
	exit(EXIT_FAILURE);
}

void	ft_error_dir(t_game *game, char c, int i)
{
	int	k;

	k = 0;
	if (c == 'D')
	{
		while (k < 6)
		{
			if (game->map->dir[k] == NULL)
			{
				printf("Error: Missing direction\n");
				ft_free_all(game);
				exit(EXIT_FAILURE);
			}
			k++;
		}
	}
	else if (c == 'I')
	{
		printf("Error: Invalid character after direction: \"%c\"\n",
			game->map->line[i]);
		ft_free_all(game);
		exit(EXIT_FAILURE);
	}
}

void	ft_error_rgb(void)
{
	printf("Error: Invalid RGB, absolute path or RGB color code\n");
	exit(EXIT_FAILURE);
}
