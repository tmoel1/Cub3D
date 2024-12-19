/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:00:27 by tmoeller          #+#    #+#             */
/*   Updated: 2024/12/18 20:27:41 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	conditiontextures(t_game *game, t_texture **selected_texture)
{
	if (game->ray->side == 0)
	{
		if (game->ray->raydirx > 0)
			*selected_texture = &game->textures.west;
		else
			*selected_texture = &game->textures.east;
	}
	else
	{
		if (game->ray->raydiry > 0)
			*selected_texture = &game->textures.north;
		else
			*selected_texture = &game->textures.south;
	}
}

static void	choose_wall_texture(t_game *game,
t_texture **selected_texture, int *tex_x)
{
	double	wall_x;

	if (game->ray->side == 0)
		wall_x = game->ply->pos_y + game->ray->perpwalldist
			* game->ray->raydiry;
	else
		wall_x = game->ply->pos_x + game->ray->perpwalldist
			* game->ray->raydirx;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * (double)game->textures.north.width);
	if (game->ray->side == 0 && game->ray->raydirx > 0)
		*tex_x = game->textures.north.width - *tex_x - 1;
	if (game->ray->side == 1 && game->ray->raydiry < 0)
		*tex_x = game->textures.north.width - *tex_x - 1;
	conditiontextures(game, selected_texture);
}

static void	draw_vertical_line(t_game *game, t_texture *texture, int tex_x)
{
	int				y;
	int				tex_y;
	double			step;
	double			tex_pos;
	unsigned int	color;

	step = 1.0 * texture->height / game->ray->line_height;
	tex_pos = (game->ray->draw_start - WIN_HEIGHT / 2
			+ game->ray->line_height / 2) * step;
	y = 0;
	while (y < game->ray->draw_start)
		my_mlx_pixel_put(&game->img, game->ray->x, y++,
			game->map->ceiling_color);
	while (y <= game->ray->draw_end)
	{
		tex_y = (int)tex_pos & (texture->height - 1);
		tex_pos += step;
		color = get_texture_color(texture, tex_x, tex_y);
		my_mlx_pixel_put(&game->img, game->ray->x, y++, color);
	}
	while (y < WIN_HEIGHT)
		my_mlx_pixel_put(&game->img, game->ray->x, y++, game->map->floor_color);
}

/*
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

// assigns textures based on wall heading as per the subject
// side 0 is a vertical wall (y axis), side 1 horizontal (x axis)
// after, chooses W/E or N/S depending on ray direction

static void	draw_vertical_line(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->ray->draw_start)
	{
		my_mlx_pixel_put(&game->img, game->ray->x, y, game->map->ceiling_color);
		y++;
	}
	while (y <= game->ray->draw_end)
	{
		my_mlx_pixel_put(&game->img, game->ray->x, y, game->ray->color);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&game->img, game->ray->x, y, game->map->floor_color);
		y++;
	}
}
*/
// draws ceiling, wall and floor in that order of the while loops
// fills all 3 sections of possible texture types of a vertical slice
// my_mlx_pixel_put sets colors of pixels directly in img buffer

void	cast_rays(t_game *game)
{
	t_texture	*texture;
	int			tex_x;

	update_frame_time(game);
	game->ray->x = 0;
	while (game->ray->x < WIN_WIDTH)
	{
		ft_init(game);
		ft_dda_algo(game);
		process_dda(game);
		perp_init(game);
		calculate_line_height(game);
		choose_wall_texture(game, &texture, &tex_x);
		draw_vertical_line(game, texture, tex_x);
		game->ray->x++;
	}
	if (BONUS_VALUE == 1)
		draw_minimap(game);
	mlx_put_image_to_window(game->p_mlx_init,
		game->p_mlx_window, game->img.i, 0, 0);
}

/*void	cast_rays(t_game *game)
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
	mlx_put_image_to_window(game->p_mlx_init,
	game->p_mlx_window, game->img.i, 0, 0);
}
// the "main" of raycasting engine
// loops across horizontally and applies all the raycasting functions to
// each x axis point and increments
// outputs final image after completing the pass
*/