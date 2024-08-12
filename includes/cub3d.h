/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 17:03:40 by shmoreno          #+#    #+#             */
/*   Updated: 2024/08/11 15:09:57 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <sys/time.h>
# include <math.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft/includes/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WINDOW_TITLE "cub3d"
# define WINDOW_WIDTH 2200
# define WINDOW_HEIGHT 1080
# define MAX_QUEUE_SIZE 1000
# define NUM_XPM_FILES 49

/*
KEY_LEFT: 97 == "A" key on the keyboard.
KEY_RIGHT: 100 == "D" key on the keyboard.
KEY_UP: 119 == "W" key on the keyboard.
KEY_DOWN: 115 == "S" key on the keyboard.
KEY_ACTION: 101 == "E" key on the keyboard.
KEY_ARROW_LEFT: 65361 == left arrow key.
KEY_ARROW_RIGHT: 65363 == right arrow key.
KEY_ARROW_UP: 65362 == up arrow key.
KEY_ARROW_DOWN: 65364 == down arrow key.
KEY_SPACE_BAR: 32 == space bar on the keyboard.
KEY_ESC: 65307 == "ESC" (escape) key on the keyboard.
*/
# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
#  define OS "linux"
#  define KEY_LEFT		97
#  define KEY_RIGHT		100
#  define KEY_UP       	119
#  define KEY_DOWN		115
#  define KEY_ARROW_LEFT	 	65361
#  define KEY_ARROW_RIGHT		65363
#  define KEY_ARROW_UP			65362
#  define KEY_ARROW_DOWN		65364
#  define KEY_ESC				65307
# elif __APPLE__
#  include "../minilibx_opengl_20191021/mlx.h"
#  define OS "macos"
#  define KEY_LEFT       0
#  define KEY_RIGHT      2
#  define KEY_UP 		13
#  define KEY_DOWN		1
#  define KEY_ARROW_LEFT		123
#  define KEY_ARROW_RIGHT		124
#  define KEY_ARROW_UP			126
#  define KEY_ARROW_DOWN		125
#  define KEY_ESC				53
# endif

// DEBUG MACROS
# define PL fprintf(stderr, "file: %s line: %d pid: %i\n", \
	__FILE__, __LINE__, getpid())
/*# define PI(x) fprintf(stderr, "PI: %d\n", (x));
# define PS(x) fprintf(stderr, "PS: %s\n", (x));
# define PI2(s, x) fprintf(stderr, "%s: %d\n", (s), (x));
# define PS2(s, x) fprintf(stderr, "%s: %s\n", (s), (x));
*/

typedef struct s_game
{
	void	*p_mlx_init;
	void	*p_mlx_window;
}	t_game;

typedef struct s_map
{
	char	**map;
	char	**directions;
	char	*line;
}	t_map;

// FUNCTION CUB3D /-\ srcs/cub3d.c
void	ft_init_main(t_map *map, char *argv);

// FUNCTION ERROR /-\ srcs/error/error.c
void	ft_error(char *str, int count);
void	ft_error_dir(t_map *map);

// FUNCTION GAME SETTINGS /-\ srcs/game/settings.c
int		ft_destroy_escape(int keysim, t_game *game);
int		ft_destroy_cross(t_game *game);
int		ft_resize_window(t_map *map);

// FUNCTION PARSING /-\ srcs/parsing/parsing.c
int		ft_parse_base(t_map *map, int argc, char **argv);

// FUNCTION PARSING /-\ srcs/parsing/parsing_map.c
void	ft_map_route(t_map *map, int count);

// FUNCTION PARSING /-\ srcs/parsing/verify_direction.c
void	ft_init_dir(t_map *map, char *line, int *count, bool *out_direction);

// FUNCTION PARSING /-\ srcs/parsing/verify_map.c
void	ft_verify_map(t_map *map, int count);

// FUNCTION UTILS /-\ srcs/utils/function_utils.c
int		ft_strlen_find(char *str, char c);
int		ft_count_index(char **input);

// FUNCTION UTILS /-\ srcs/utils/parsing_utils.c
bool	ft_only_espace(const char *line);
bool	ft_only_iswall(const char *line);
int		ft_malloc_size(char *argv);
int		ft_check_dir(t_map *map);

#endif