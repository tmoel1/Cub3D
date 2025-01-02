/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:00:26 by shmoreno          #+#    #+#             */
/*   Updated: 2024/12/21 15:03:47 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_malloc_size(char *argv)
{
	char	*line;
	int		fd;
	int		size;

	size = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		(printf("Error: Invalid file\n"), exit(EXIT_FAILURE));
	line = get_next_line(fd);
	while (line != NULL)
	{
		size++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (size);
}

bool	ft_only_espace(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[0] != '\n')
			return (false);
		i++;
	}
	return (true);
}

bool	ft_only_iswall(const char *line)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (line[i++] != '\0')
	{
		if (line[i] == ' ' || line[i] == '\t'
			|| line[i] == '\n' || line[i] == '\0')
			continue ;
		else if (line[i] == '1')
		{
			count++;
			continue ;
		}
		else
			return (false);
	}
	if (count > 0)
		return (true);
	return (false);
}

void	ft_check_espace(t_game *game, int i, bool norgb)
{
	i += 2;
	while (game->map->line[i] != '\0')
	{
		if (game->map->line[i] == '.' && game->map->line[i + 1] == '/' && norgb)
			return ;
		if ((ft_isdigit(game->map->line[i]) && !norgb)
			|| (game->map->line[i] == ','
				&& ft_isdigit(game->map->line[i - 1]) && !norgb))
			return ;
		else if (!(game->map->line[i] == ' ' || game->map->line[i] == '\t'
				|| game->map->line[i] == '\n'))
			ft_error_dir(game, 'I', i);
		i++;
	}
}

int	ft_check_dir(t_game *game)
{
	int	i;

	i = -1;
	while (game->map->line && game->map->line[++i] != '\0')
	{
		if (game->map->line[i] == 'N' && game->map->line[i + 1] == 'O'
			&& game->map->line[i + 2] == ' ')
			return (ft_check_espace(game, i, true), 0);
		else if (game->map->line[i] == 'S' && game->map->line[i + 1] == 'O'
			&& game->map->line[i + 2] == ' ')
			return (ft_check_espace(game, i, true), 1);
		else if (game->map->line[i] == 'W' && game->map->line[i + 1] == 'E'
			&& game->map->line[i + 2] == ' ')
			return (ft_check_espace(game, i, true), 2);
		else if (game->map->line[i] == 'E' && game->map->line[i + 1] == 'A'
			&& game->map->line[i + 2] == ' ')
			return (ft_check_espace(game, i, true), 3);
		else if (game->map->line[i] == 'F' && game->map->line[i + 1] == ' ')
			return (ft_check_espace(game, i, false), 4);
		else if (game->map->line[i] == 'C' && game->map->line[i + 1] == ' ')
			return (ft_check_espace(game, i, false), 5);
	}
	return (-1);
}
