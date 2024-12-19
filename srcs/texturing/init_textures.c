/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:10:51 by tmoeller          #+#    #+#             */
/*   Updated: 2024/12/18 12:50:21 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_texture(t_game *game, t_texture *texture, char *path)
{
	texture->i = mlx_xpm_file_to_image(game->p_mlx_init, path,
			&texture->width, &texture->height);
	if (!texture->i)
		ft_error("Failed to load texture", 0);
	texture->addr = mlx_get_data_addr(texture->i,
			&texture->bpp, &texture->line_len, &texture->endian);
}

void	init_textures(t_game *game)
{
	load_texture(game, &game->textures.north, game->map->dir[0]);
	load_texture(game, &game->textures.south, game->map->dir[1]);
	load_texture(game, &game->textures.west, game->map->dir[2]);
	load_texture(game, &game->textures.east, game->map->dir[3]);
}

unsigned int	get_texture_color(t_texture *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)pixel);
}
