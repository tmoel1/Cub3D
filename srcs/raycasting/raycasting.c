/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:44:51 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/01 13:47:15 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_init_raycast(t_map *game)
{
	game->ray->dirx = 0.0;
	game->ray->diry = 0.0;
	game->ray->planex = 0.0;
	game->ray->planey = 0.0;
	game->ray->raydirx = 0.0;
	game->ray->raydiry = 0.0;
	game->ray->sidedistx = 0.0;
	game->ray->sidedisty = 0.0;
	game->ray->x = 0;
	game->ray->mapx = 0;
	game->ray->mapy = 0;
}

void	ft_init(t_map *game)
{
	game->ray->camerax = 2 * game->ray->x / (double)WINDOW_WIDTH - 1;
	game->ray->raydirx = game->ray->dirx + game->ray->planex * game->ray->camerax;
	game->ray->raydiry = game->ray->diry + game->ray->planey * game->ray->camerax;
}
