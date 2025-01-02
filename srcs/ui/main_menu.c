/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:58:07 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/20 12:34:12 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_space_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_SPACE && !game->b_menu)
	{
		printf("Start game\n");
		game->b_menu = true;
		mlx_clear_window(game->p_mlx_init, game->p_mlx_window);
	}
	return (0);
}

int	ft_mouse_click(int button, int x, int y, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (button == 1 && !game->b_menu && x > 0 && x < WIN_WIDTH
		&& y > 0 && y < WIN_HEIGHT)
	{
		printf("Start game\n");
		game->b_menu = true;
		mlx_clear_window(game->p_mlx_init, game->p_mlx_window);
		return (0);
	}
	return (1);
}

//Draw the main menu
void	ft_main_menu(t_game *game)
{
	int		width;
	int		height;

	width = WIN_WIDTH;
	height = WIN_HEIGHT;
	game->img_menu = mlx_xpm_file_to_image(game->p_mlx_init,
			"./assets/ui/main_menu.xpm", &width, &height);
	if (!game->b_menu && game->img_menu)
	{
		mlx_put_image_to_window(game->p_mlx_init,
			game->p_mlx_window, game->img_menu, 0, 0);
	}
}
