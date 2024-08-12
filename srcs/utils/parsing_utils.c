/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:00:26 by shmoreno          #+#    #+#             */
/*   Updated: 2024/08/12 14:19:50 by shmoreno         ###   ########.fr       */
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
		if (line[i] != ' ' && line[i] != '\t'
			&& line[0] != '\n')
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

void	ft_check_espace(t_map *map, int i)
{
	i += 2;
	while (map->line[i] != '\0')
	{
		if ((map->line[i] == '.' && map->line[i + 1] == '/')
			|| ft_isdigit(map->line[i]) == 1)
			return ;
		if (map->line[i] == ' ' || map->line[i] == '\t')
			i++;
		else
		{
			(printf("Error: Invalid character after direction: \"%c\"\n",
					map->line[i]), exit(EXIT_FAILURE));
		}
	}
}

int	ft_check_dir(t_map *map)
{
	int	i;

	i = -1;
	while (map->line && map->line[++i] != '\0')
	{
		if (map->line[i] == 'N' && map->line[i + 1] == 'O'
			&& map->line[i + 2] == ' ')
			return (ft_check_espace(map, i), 0);
		else if (map->line[i] == 'S' && map->line[i + 1] == 'O'
			&& map->line[i + 2] == ' ')
			return (ft_check_espace(map, i), 1);
		else if (map->line[i] == 'W' && map->line[i + 1] == 'E'
			&& map->line[i + 2] == ' ')
			return (ft_check_espace(map, i), 2);
		else if (map->line[i] == 'E' && map->line[i + 1] == 'A'
			&& map->line[i + 2] == ' ')
			return (ft_check_espace(map, i), 3);
		else if (map->line[i] == 'F' && map->line[i + 1] == ' ')
			return (ft_check_espace(map, i), 4);
		else if (map->line[i] == 'C' && map->line[i + 1] == ' ')
			return (ft_check_espace(map, i), 5);
	}
	return (-1);
}
