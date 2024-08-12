/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:06:45 by shmoreno          #+#    #+#             */
/*   Updated: 2024/08/11 14:13:53 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_hook(t_game *game)
{
	//mlx_mouse_hook(game->p_mlx_window, &ft_mouse_click, map); //Ecran de chargement
	mlx_hook(game->p_mlx_window, 3, (1L << 1), &ft_destroy_escape, game);
	mlx_hook(game->p_mlx_window, 17, 0, &ft_destroy_cross, game);
	//mlx_hook(game->p_mlx_window, 12, (1L << 17), &ft_resize_window, game);
}

// directions[0][0] == NO
// directions[1][0] == SO
// directions[2][0] == WE
// directions[3][0] == EA
// directions[4][0] == F
// directions[5][0] == C
void	ft_init_main(t_map *map, char *argv)
{
	int	i;

	i = -1;
	map->map = malloc(sizeof(char *) * ft_malloc_size(argv) + 1);
	map->line = NULL;
	map->directions = malloc(sizeof(char *) * 6);
	if (!map->directions)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (++i < 6)
		map->directions[i] = NULL;
	i = -1;
	printf("malloc size: %d\n", ft_malloc_size(argv));
	while (++i < ft_malloc_size(argv))
		map->map[i] = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	if (ft_parse_base(&map, argc, argv) == 1)
		exit(EXIT_FAILURE);
	game.p_mlx_init = mlx_init();
	if (!game.p_mlx_init)
		return (EXIT_FAILURE);
	game.p_mlx_window = mlx_new_window(game.p_mlx_init, WINDOW_WIDTH,
			WINDOW_HEIGHT, WINDOW_TITLE);
	if (!game.p_mlx_window)
	{
		return (EXIT_FAILURE);
	}
	//mlx_loop_hook(game.p_mlx_init, &ft_update_game, &map);
	ft_hook(&game);
	mlx_loop(game.p_mlx_init);
	return (0);
}
