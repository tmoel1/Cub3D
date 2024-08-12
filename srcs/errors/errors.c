/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:13:02 by shmoreno          #+#    #+#             */
/*   Updated: 2024/08/11 15:08:05 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error(char *str, int count)
{
	printf("Error: %s: line %d\n", str, count);
	exit(EXIT_FAILURE);
}

void	ft_error_dir(t_map *map)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (map->directions[i] == NULL)
			(printf("Error: Missing direction\n"), exit(EXIT_FAILURE));
		i++;
	}
}
