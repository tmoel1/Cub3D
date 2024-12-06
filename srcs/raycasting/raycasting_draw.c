/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:00:27 by tmoeller          #+#    #+#             */
/*   Updated: 2024/12/06 12:52:18 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	choose_wall_texture(t_game *game)
{
	if (game->ray->side == 0)
	{
		if (game->ray->raydirx > 0)
			game->ray->color = WEST_WALL_TEXTURE;
		else
			game->ray->color = EAST_WALL_TEXTURE;
	}
	else
	{
		if (game->ray->raydiry > 0)
			game->ray->color = NORTH_WALL_TEXTURE;
		else
			game->ray->color = SOUTH_WALL_TEXTURE;
	}
}

static void	draw_vertical_line(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->ray->draw_start)
	{
		my_mlx_pixel_put(&game->img, game->ray->x, y, CEILING_COLOR);
		y++;
	}
	// Draw wall
	while (y <= game->ray->draw_end)
	{
		my_mlx_pixel_put(&game->img, game->ray->x, y, game->ray->color);
		y++;
	}
	// Draw floor
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&game->img, game->ray->x, y, FLOOR_COLOR);
		y++;
	}
}

void	cast_rays(t_game *game)
{
	update_frame_time(game);
	game->ray->x = 0;
	while (game->ray->x < WIN_WIDTH)
	{
		ft_init(game);
		ft_dda_algo(game);
		process_dda(game);
		perp_init(game);
		calculate_line_height(game);
		choose_wall_texture(game);
		draw_vertical_line(game);
		game->ray->x++;
	}
	mlx_put_image_to_window(game->p_mlx_init, game->p_mlx_window, game->img.i, 0, 0);
}
