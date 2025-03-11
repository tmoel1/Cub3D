/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:57:21 by shmoreno          #+#    #+#             */
/*   Updated: 2025/03/11 17:56:51 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_dir_base(t_game *game, int *count, int index, int size)
{
	int	i;
	int	count_rgb;

	i = -1;
	count_rgb = 0;
	count[index]++;
	if (count[index] > 1)
		ft_error(game, "Duplicate direction", count[6]);
	if (game->map->dir[index] == NULL)
	{
		game->map->dir[index] = ft_substr(game->map->line, size,
				ft_strlen(game->map->line) - size - 1);
		if (game->map->dir[index] == NULL)
			ft_error(game, "Malloc failed", count[6]);
		if (index == 4 || index == 5)
		{
			ft_find_rgb(game, index, i, count_rgb);
		}
	}
}

void	ft_init_dir(t_game *game, char *line, int *count, bool *out_direction)
{
	if (ft_only_iswall(line) && !*out_direction)
		*out_direction = true;
	if (!*out_direction)
	{
		count[6]++;
		if (ft_check_dir(game) == 0)
			ft_dir_base(game, count, 0, ft_strlen_find(line, '.'));
		else if (ft_check_dir(game) == 1)
			ft_dir_base(game, count, 1, ft_strlen_find(line, '.'));
		else if (ft_check_dir(game) == 2)
			ft_dir_base(game, count, 2, ft_strlen_find(line, '.'));
		else if (ft_check_dir(game) == 3)
			ft_dir_base(game, count, 3, ft_strlen_find(line, '.'));
		else if (ft_check_dir(game) == 4)
			ft_dir_base(game, count, 4, ft_strlen_find(line, 'N'));
		else if (ft_check_dir(game) == 5)
			ft_dir_base(game, count, 5, ft_strlen_find(line, 'N'));
		else if (ft_only_espace(line))
			return ;
		else
			ft_error(game, "Invalid direction", count[6]);
	}
}
