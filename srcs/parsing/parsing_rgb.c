/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoeller <tmoeller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:21:48 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/19 14:19:31 by tmoeller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_rgb_to_hex(int red, int green, int blue)
{
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}

void	ft_convert_rgb(t_map *map, int index, int *rgb, int c_separate)
{
	int	i;

	i = -1;
	if (c_separate != 2)
		ft_error_rgb();
	while (++i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_error_rgb();
	}
	if (index == 4)
		map->floor_color = ft_rgb_to_hex(rgb[0], rgb[1], rgb[2]);
	else if (index == 5)
		map->ceiling_color = ft_rgb_to_hex(rgb[0], rgb[1], rgb[2]);
}

void	ft_substr_rgb(t_map *map, int index, int i, int count_rgb)
{
	if (map->dir[index][i + 1] == '\0')
		map->tmp = ft_substr(map->dir[index], i - count_rgb, count_rgb + 1);
	else
		map->tmp = ft_substr(map->dir[index], i - count_rgb, count_rgb);
}

void	ft_find_rgb(t_map *map, int index, int i, int count_rgb)
{
	int		k;
	int		c_separate;
	int		rgb[3];

	k = -1;
	c_separate = 0;
	while (map->dir[index][++i] != '\0')
	{
		if ((map->dir[index][i] == ',' && ft_isdigit(map->dir[index][i + 1]))
		|| (ft_isdigit(map->dir[index][i]) && map->dir[index][i + 1] == '\0'))
		{
			if (map->dir[index][i] == ',')
				c_separate++;
			if (c_separate > 3)
				ft_error_rgb();
			ft_substr_rgb(map, index, i, count_rgb);
			rgb[++k] = ft_atoi(map->tmp);
			(free(map->tmp), count_rgb = 0);
		}
		else if (ft_isdigit(map->dir[index][i]))
			count_rgb++;
		else
			ft_error_rgb();
	}
	ft_convert_rgb(map, index, rgb, c_separate);
}
