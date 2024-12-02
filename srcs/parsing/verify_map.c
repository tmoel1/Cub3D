/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:09:50 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/01 17:21:27 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//Supprimer les parantheses si rien a rajouter + ce comm
void	ft_init_coords(t_map *map, t_game *game, int k, int i)
{
	if (map->map[k][i] == 'N' || map->map[k][i] == 'S'
		|| map->map[k][i] == 'E' || map->map[k][i] == 'W')
	{
		game->ply->pos_x = (float)i;
		game->ply->pos_y = (float)k + 1;
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

void	ft_verify_caracter(char map_c, int count, int *verify_dir)
{
	if (map_c == 'N' || map_c == 'S' || map_c == 'E' || map_c == 'W')
		(*verify_dir)++;
	if (*verify_dir > 1)
		ft_error("Duplicate direction in the map", count);
	if (map_c != '0' && map_c != '1' && map_c != 'N' && map_c != 'S'
		&& map_c != 'E' && map_c != 'W' && map_c != ' ' && map_c != '\n'
		&& map_c != '\t')
		ft_error("Invalid character in the map", count);
}

void	ft_verify_map(t_map *map, t_game *game, int count)
{
	char	map_c;
	int		i;
	int		k;
	int		verify_dir;

	k = -1;
	verify_dir = 0;
	while (map->map[++k] != NULL)
	{
		i = -1;
		count++;
		if (ft_only_espace(map->map[k]) || ft_strlen(map->map[k]) == 0)
			ft_error("Empty line between map", count);
		while (map->map[k][++i] != '\0')
		{
			map_c = map->map[k][i];
			ft_init_coords(map, game, k, i);
			ft_verify_caracter(map_c, count, &verify_dir);
		}
	}
	if (verify_dir == 0)
		ft_error("No direction in the map", count);
}
