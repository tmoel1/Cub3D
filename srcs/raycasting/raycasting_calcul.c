/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_calcul.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:31:37 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/01 17:14:51 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	process_dda(t_game *game)
{
	while (game->ray->hit == 0)
	{
		if (game->ray->sidedistx < game->ray->sidedisty)
		{
			game->ray->sidedistx += game->ray->deltadistx;
			game->ray->mapx += game->ray->stepx;
			game->ray->side = 0;
		}
		else
		{
			game->ray->sidedisty += game->ray->deltadisty;
			game->ray->mapy += game->ray->stepy;
			game->ray->side = 1;
		}
		if (game->map->map[game->ray->mapy][game->ray->mapx] == '1')
		{
			game->ray->hit = 1;
			if (game->ray->side == 0)
				game->ray->perpwalldist = (game->ray->sidedistx - \
				game->ray->deltadistx);
			else
				game->ray->perpwalldist = (game->ray->sidedisty - \
				game->ray->deltadisty);
		}
	}
}
