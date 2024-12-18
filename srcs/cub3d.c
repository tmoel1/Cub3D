/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 12:06:45 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/18 12:49:25 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//new
void	ft_hook(t_game *game)
{
	mlx_hook(game->p_mlx_window, 2, (1L<<0), &key_press, game);
	mlx_hook(game->p_mlx_window, 3, (1L<<1), &key_release, game);
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
	game->map->line = NULL;
	game->map->dir = malloc(sizeof(char *) * 6);
	game->map->floor_color = 0;
	game->map->ceiling_color = 0;
	game->ply->pos_x = 0.0;
	game->ply->pos_y = 0.0;
	game->ply->dir_angle = 0.0;
	game->ply->angle = 0.0;
	game->ply->pov_rad = 0.0;
	if (!game->map->dir)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	while (++i < 6)
		game->map->dir[i] = NULL;
	i = -1;
	while (++i < ft_malloc_size(argv))
		game->map->map[i] = NULL;
}

int	main(int argc, char **argv) //too long
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
	if (!game.p_mlx_init)
		return (EXIT_FAILURE);
	init_textures(&game); // added
	game.p_mlx_window = mlx_new_window(game.p_mlx_init, WIN_WIDTH,
			WIN_HEIGHT, WINDOW_TITLE);
	if (!game.p_mlx_window)
		return (EXIT_FAILURE);
	game.img.i = mlx_new_image(game.p_mlx_init, WIN_WIDTH, WIN_HEIGHT);
	if (!game.img.i)
		return (EXIT_FAILURE);
	game.img.addr = mlx_get_data_addr(game.img.i, &game.img.bpp,
		&game.img.line_len, &game.img.endian);
	//mlx_mouse_move(game.p_mlx_init, game.p_mlx_window, MID_X, MID_Y);			// A AJOUTER
	//mlx_hook(game.p_mlx_window, 6, (1L<<6), mouse_move, &game);					// A AJOUTER
	mlx_loop_hook(game.p_mlx_init, &ft_update_game, &game);
	ft_hook(&game);
	mlx_loop(game.p_mlx_init);
	return (0);
}

