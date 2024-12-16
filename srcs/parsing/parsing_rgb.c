/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:21:48 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/15 23:02:52 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_check_rgb_color(t_map *map, int i, int *c_rgb, int *c_separate)
{
	if (map->line[i] > '2' && *c_rgb == 1
		&& ft_isdigit(map->line[i + 1]) && ft_isdigit(map->line[i + 2]))
		ft_error_dir(map, 'I', i);
	else if ((map->line[i] > '5' && *c_rgb == 2 && ft_isdigit(map->line[i + 1]))
		|| (map->line[i] > '5' && *c_rgb == 3))
		ft_error_dir(map, 'I', i);
	if (map->line[i] == ',' && (*c_rgb >= 1 && *c_rgb <= 3))
	{
		*c_rgb = 0;
		*c_separate += 1;
	}
	else if (*c_rgb > 3 || (i == ft_strlen(map->line) && *c_separate != 2))
		ft_error_rgb();
}

void	convertRGBtoHexa(int n)
{
	char	hexa[3];
	int		resulthexa;
	int		i;

	resulthexa = 0;
	i = 7;
	hexa[3] = '\0';
	while (n > 0)
	{
		resulthexa = n % 16;
		if (resulthexa < 10)
			hexa[i] = resulthexa + 48;
		else
			hexa[i] = resulthexa + 55;
		n = n / 16;
		i--;
	}
	printf("%s\n", hexa);
}
