/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:21:48 by shmoreno          #+#    #+#             */
/*   Updated: 2025/03/11 20:45:12 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

void	ft_convert_rgb(t_game *game, int index, int *rgb, int c_separate)
{
	int	i;

	i = -1;
	if (c_separate != 2)
		ft_error_rgb(game);
	while (++i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_error_rgb(game);
	}
	if (index == 4)
		game->map->floor_color = ft_rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	else if (index == 5)
		game->map->ceiling_color = ft_rgb_to_hex(rgb[0], rgb[1], rgb[2]);
}

void	ft_substr_rgb(t_game *game, int index, int i, int count_rgb)
{
	if (game->map->dir[index][i + 1] == '\0')
		game->map->tmp = ft_substr(game->map->dir[index],
				i - count_rgb, count_rgb + 1);
	else
		game->map->tmp = ft_substr(game->map->dir[index],
				i - count_rgb, count_rgb);
}

void	ft_find_rgb(t_game *game, int index, int i, int count_rgb)
{
	int		k;
	int		c_separate;
	int		rgb[3];

	k = -1;
	c_separate = 0;
	while (game->map->dir[index][++i] != '\0')
	{
		if ((game->map->dir[index][i] == ','
			&& ft_isdigit(game->map->dir[index][i + 1]))
			|| (ft_isdigit(game->map->dir[index][i])
			&& game->map->dir[index][i + 1] == '\0'))
		{
			if (game->map->dir[index][i] == ',')
				c_separate++;
			if (c_separate > 3)
				ft_error_rgb(game);
			ft_substr_rgb(game, index, i, count_rgb);
			rgb[++k] = ft_atoi(game->map->tmp);
			(free(game->map->tmp), count_rgb = 0);
		}
		else if (ft_isdigit(game->map->dir[index][i]))
			count_rgb++;
		else
			ft_error_rgb(game);
	}
	ft_convert_rgb(game, index, rgb, c_separate);
}
