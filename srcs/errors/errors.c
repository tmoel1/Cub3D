/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:13:02 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/17 12:19:31 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error(char *str, int count)
{
	printf("Error: %s: line %d\n", str, count);
	exit(EXIT_FAILURE);
}

void	ft_error_dir(t_map *map, char c, int i)
{
	int	k;

	k = 0;
	if (c == 'D')
	{
		while (k < 6)
		{
			if (map->dir[k] == NULL)
				(printf("Error: Missing direction\n"), exit(EXIT_FAILURE));
			k++;
		}
	}
	else if (c == 'I')
	{
		printf("Error: Invalid character after direction: \"%c\"\n",
			map->line[i]);
		exit(EXIT_FAILURE);
	}
}

void	ft_error_rgb(void)
{
	printf("Error: Invalid RGB, absolute path or RGB color code\n");
	exit(EXIT_FAILURE);
}
