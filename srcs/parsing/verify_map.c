/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:09:50 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/20 13:58:19 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_coords(t_map *map, t_game *game, int k, int i)
{
	if (map->map[k][i] == 'N' || map->map[k][i] == 'S'
		|| map->map[k][i] == 'E' || map->map[k][i] == 'W')
	{
		game->ply->pos_x = (float)i + 0.5;
		game->ply->pos_y = (float)k + 0.5;
		if (map->map[k][i] == 'N')
		{
			game->ply->dir_angle = 270.0;
		}
		else if (map->map[k][i] == 'S')
		{
			game->ply->dir_angle = 90.0;
		}
		else if (map->map[k][i] == 'E')
		{
			game->ply->dir_angle = 0.0;
		}
		else if (map->map[k][i] == 'W')
		{
			game->ply->dir_angle = 180.0;
		}
	}
}

void	ft_verify_caracter(t_game *game, char map_c, int count, int *verify_dir)
{
	if (map_c == 'N' || map_c == 'S' || map_c == 'E' || map_c == 'W')
		(*verify_dir)++;
	if (*verify_dir > 1)
		ft_error(game, "Duplicate direction in the map", count);
	if (map_c != '0' && map_c != '1' && map_c != 'N' && map_c != 'S'
		&& map_c != 'E' && map_c != 'W' && map_c != ' ' && map_c != '\n'
		&& map_c != '\t')
		ft_error(game, "Invalid character in the map", count);
}

void	ft_verify_map(t_game *game, int count)
{
	char	map_c;
	int		i;
	int		k;
	int		verify_dir;

	k = -1;
	verify_dir = 0;
	while (game->map->map[++k] != NULL)
	{
		i = -1;
		count++;
		if (ft_only_espace(game->map->map[k])
			|| ft_strlen(game->map->map[k]) == 0)
			ft_error(game, "Empty line between map", count);
		while (game->map->map[k][++i] != '\0')
		{
			map_c = game->map->map[k][i];
			ft_init_coords(game->map, game, k, i);
			ft_verify_caracter(game, map_c, count, &verify_dir);
		}
	}
	if (verify_dir == 0)
		ft_error(game, "No direction in the map", count);
}
