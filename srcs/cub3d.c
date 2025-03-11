/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:06:45 by shmoreno          #+#    #+#             */
/*   Updated: 2025/03/11 20:17:14 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bonus(t_game *game)
{
	if (BONUS_VALUE == 1)
	{
		mlx_mouse_move(game->p_mlx_init, game->p_mlx_window,
			game->mid_x, game->mid_y);
		mlx_hook(game->p_mlx_window, 6, (1L << 6), mouse_move, game);
	}
}

void	ft_hook(t_game *game)
{
	mlx_mouse_hook(game->p_mlx_window, &ft_mouse_click, game);
	mlx_hook(game->p_mlx_window, 2, (1L << 0), &key_press, game);
	mlx_hook(game->p_mlx_window, 3, (1L << 1), &key_release, game);
	mlx_hook(game->p_mlx_window, 17, 0, &ft_destroy_cross, game);
}

// directions[0][0] == NO
// directions[1][0] == SO
// directions[2][0] == WE
// directions[3][0] == EA
// directions[4][0] == F
// directions[5][0] == C
void	ft_init_main(t_game *game, char *argv)
{
	int	i;

	i = -1;
	game->map->map = malloc(sizeof(char *) * ft_malloc_size(argv) + 1);
	game->map->dir = malloc(sizeof(char *) * 6);
	if (!game->map->dir || !game->map->map)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	game->map->line = NULL;
	game->map->floor_color = 0;
	game->map->ceiling_color = 0;
	game->index_map = 0;
	game->mid_x = WIN_WIDTH / 2;
	game->mid_y = WIN_HEIGHT / 2;
	game->b_menu = false;
	game->ply->pos_x = 0.0;
	game->ply->pos_y = 0.0;
	game->ply->dir_angle = 0.0;
	while (++i < 6)
		game->map->dir[i] = NULL;
	i = -1;
	while (++i < ft_malloc_size(argv))
		game->map->map[i] = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;
	t_ply	ply;
	t_ray	ray;

	game.ply = &ply;
	game.ray = &ray;
	game.map = &map;
	if (ft_parse_base(&game, argc, argv) == 1)
		exit(EXIT_FAILURE);
	init_player(&game);
	ft_init_raycast(&game);
	game.p_mlx_init = mlx_init();
	init_textures(&game);
	game.p_mlx_window = mlx_new_window(game.p_mlx_init, WIN_WIDTH,
			WIN_HEIGHT, WINDOW_TITLE);
	game.img.i = mlx_new_image(game.p_mlx_init, WIN_WIDTH, WIN_HEIGHT);
	if (!game.p_mlx_init || !game.p_mlx_window || !game.img.i)
		return (EXIT_FAILURE);
	game.img.addr = mlx_get_data_addr(game.img.i, &game.img.bpp,
			&game.img.line_len, &game.img.endian);
	ft_bonus(&game);
	ft_main_menu(&game);
	mlx_loop_hook(game.p_mlx_init, &ft_update_game, &game);
	(ft_hook(&game), mlx_loop(game.p_mlx_init));
	return (0);
}
