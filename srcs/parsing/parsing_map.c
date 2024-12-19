/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:00:19 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/15 14:43:29 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_notwall(char c)
{
	if (c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (1);
	return (0);
}

void	ft_condition_bis(t_map *map, int k, int i, int count)
{
	if (i == ft_strlen(map->map[k]) - 1
		&& map->map[k][i] != '1' && map->map[k][i] != ' '
	&& map->map[k][i] != '\t' && map->map[k][i] != '\n')
	{
		ft_error("Invalid map", count);
	}
	else if (map->map[k][i] == '0'
		&& ((ft_strlen(map->map[k - 1]) - 2 < i)
		|| (ft_strlen(map->map[k]) - 2 == i)))
		ft_error("Invalid map", count);
}

int	ft_condition_route(t_map *map, int k, int i, int count)
{
	if (i == 0 && !ft_notwall(map->map[k][i]))
		ft_error("Invalid map", count);
	else if (i > 0 && i < ft_strlen(map->map[k]) - 1)
	{
		if (map->map[k][i] == ' ' && k > 0
			&& map->map[k - 1] != NULL
			&& i < ft_strlen(map->map[k - 1]) - 1
			&& !ft_notwall(map->map[k - 1][i]))
			ft_error("Invalid map", (count - 1));
		else if (map->map[k][i] == ' '
			&& k < ft_count_index(map->map) - 1
			&& map->map[k + 1] != NULL
			&& i < ft_strlen(map->map[k + 1]) - 1
			&& !ft_notwall(map->map[k + 1][i]))
			ft_error("Invalid map", count + 1);
		else if (map->map[k][i] == ' '
			&& (((i + 1) < ft_strlen(map->map[k]) - 1
			&& !ft_notwall(map->map[k][i + 1]))
			|| ((i - 1) >= 0 && !ft_notwall(map->map[k][i - 1]))))
			ft_error("Invalid map", count);
	}
	ft_condition_bis(map, k, i, count);
	return (1);
}

void	ft_map_route(t_game *game, int count)
{
	int		i;
	int		k;

	k = 0;
	ft_verify_map(game, count);
	if (!ft_only_iswall(game->map->map[0])
		|| !ft_only_iswall(game->map->map[ft_count_index(game->map->map) - 1]))
		ft_error("First or last line does not contain only walls", count);
	count++;
	while (game->map->map[++k] != NULL)
	{
		i = -1;
		count++;
		while (game->map->map[k][++i] != '\0')
		{
			if (ft_condition_route(game->map, k, i, count) == 1)
				continue ;
		}
	}
}
