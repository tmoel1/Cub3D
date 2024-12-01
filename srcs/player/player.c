/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:18:33 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/01 16:53:11 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_ply(t_game *game)
{
	game->ply->pov_rad = (PLY_POV * M_PI) / 180;
	game->ply->pov_rad = M_PI;
}
