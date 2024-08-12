/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:09:50 by shmoreno          #+#    #+#             */
/*   Updated: 2024/08/11 14:17:57 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_verify_caractere(char map_c, int count, int *verify_dir)
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

void	ft_verify_map(t_map *map, int count)
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
			ft_verify_caractere(map_c, count, &verify_dir);
		}
	}
	if (verify_dir == 0)
		ft_error("No direction in the map", count);
}
