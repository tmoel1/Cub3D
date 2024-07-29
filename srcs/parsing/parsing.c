/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:58:35 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/28 13:10:53 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_parse_base(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error: Invalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
	{
		printf("Error: Invalid file extension\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
