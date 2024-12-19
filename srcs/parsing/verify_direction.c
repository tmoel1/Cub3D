/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:57:21 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/19 12:32:27 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_dir_base(t_map *map, int *count, int index, int size)
{
	int	i;
	int	count_rgb;

	i = -1;
	count_rgb = 0;
	count[index]++;
	if (count[index] > 1)
		(printf("Error: Duplicate direction: line %d\n", count[6]),
			exit(EXIT_FAILURE));
	if (map->dir[index] == NULL)
	{
		map->dir[index] = ft_substr(map->line, size,
				ft_strlen(map->line) - size - 1);
		if (index == 4 || index == 5)
		{
			ft_find_rgb(map, index, i, count_rgb);
		}
	}
}

// Modifier peut-etre car premiere ligne return invalid direction
void	ft_init_dir(t_map *map, char *line, int *count, bool *out_direction)
{
	if (ft_only_iswall(line) && !*out_direction)
		*out_direction = true;
	if (!*out_direction)
	{
		count[6]++;
		if (ft_check_dir(map) == 0)
			ft_dir_base(map, count, 0, ft_strlen_find(line, '.'));
		else if (ft_check_dir(map) == 1)
			ft_dir_base(map, count, 1, ft_strlen_find(line, '.'));
		else if (ft_check_dir(map) == 2)
			ft_dir_base(map, count, 2, ft_strlen_find(line, '.'));
		else if (ft_check_dir(map) == 3)
			ft_dir_base(map, count, 3, ft_strlen_find(line, '.'));
		else if (ft_check_dir(map) == 4)
			ft_dir_base(map, count, 4, ft_strlen_find(line, 'N'));
		else if (ft_check_dir(map) == 5)
			ft_dir_base(map, count, 5, ft_strlen_find(line, 'N'));
		else if (ft_only_espace(line))
			return ;
		else
			(printf("Error: Invalid direction: line %d\n", count[6]),
				exit(EXIT_FAILURE));
	}
}
