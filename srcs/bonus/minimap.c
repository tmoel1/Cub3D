/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:08:36 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/18 23:19:43 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

void	chose_color_tiles_and_draw_it(t_game *game,
t_coord coord, t_coord pixel)
{
	if (game->map->map[coord.y][coord.x] == '1')
		my_mlx_pixel_put(&game->img, coord.x * TILES_SIZE
			+ pixel.x, coord.y * TILES_SIZE + pixel.y, MINIMAP_WALL);
	else if (game->map->map[coord.y][coord.x] == '0'
		|| ft_strchr("NSEW", game->map->map[coord.y][coord.x]) != NULL)
		my_mlx_pixel_put(&game->img, coord.x * TILES_SIZE
			+ pixel.x, coord.y * TILES_SIZE + pixel.y, MINIMAP_FLOOR);
}

void	draw_tiles(t_game *game)
{
	t_coord	coord;
	t_coord	pixel;

	coord.y = -1;
	while (game->map->map[++coord.y])
	{
		coord.x = 0;
		while (game->map->map[coord.y][coord.x])
		{
			if (ft_isspace(game->map->map[coord.y][coord.x]) == 1)
			{
				coord.x++;
				continue ;
			}
			pixel.y = 0;
			while (pixel.y < TILES_SIZE)
			{
				pixel.x = -1;
				while (++pixel.x < TILES_SIZE)
					chose_color_tiles_and_draw_it(game, coord, pixel);
				pixel.y++;
			}
			coord.x++;
		}
	}
}

void	draw_player(t_game *game)
{
	t_coord	pixel;

	pixel.y = 0;
	while (pixel.y < PLAYER_SIZE)
	{
		pixel.x = 0;
		while (pixel.x < PLAYER_SIZE)
		{
			my_mlx_pixel_put(&game->img, game->ply->pos_x * TILES_SIZE + \
				pixel.x, game->ply->pos_y * TILES_SIZE
				+ pixel.y, MINIMAP_PLAYER);
			pixel.x++;
		}
		pixel.y++;
	}
}

void	draw_minimap(t_game *game)
{
	draw_tiles(game);
	draw_player(game);
}
