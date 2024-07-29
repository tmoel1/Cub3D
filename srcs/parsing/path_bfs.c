/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bfs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:00:19 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/28 21:29:11 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Fonction qui vérifie si la nouvelle position est valide
// Si la nouvelle position est valide, elle est ajoutée à la file d'attente
// Si la nouvelle position est en dehors de la carte/mur, elle est ignorée
void	ft_verify_new_pos(t_node *node, t_map *map,
    t_queue *q, bool **visited)
{
	int		i;
	int		n_x;
	int		n_y;

	i = 0;
	while (i < 4)
	{
		ft_direction(*node, i, &n_x, &n_y);
		if (n_x >= 0 && n_x < map->c_collumns && n_y >= 0
			&& n_y < map->c_lines && map->p_map[n_x][n_y] != '1' && !visited[n_x][n_y])
		{
			visited[n_x][n_y] = true;
			ft_enqueue(q, n_x, n_y);
		}
		i++;
	}
}

// Fonction qui initialise le BFS
void	ft_initialize_bfs(t_map *map, t_node *start,
    t_queue *q, bool ***visited)
{
	t_node	*start_node;

	q->front = 0;
	q->rear = 0;
	ft_visited_init(map, visited);
	(*visited)[start->x][start->y] = true;
	start_node = malloc(sizeof(t_node));
	ft_malloc_error(start_node);
	*start_node = *start;
	ft_enqueue(q, start_node->x, start_node->y);
	free(start_node);
}

// Fonction qui vérifie si une position est sur le bord de la carte
bool	ft_is_on_border(int x, int y, t_map *map)
{
	return (x == 0 || x == map->c_collumns - 1 || y == 0 || y == map->c_lines - 1);
}

// Fonction qui effectue le BFS
void	ft_perform_bfs(t_map *map, t_node *goal, t_queue *q, bool **visited)
{
	t_node	*node;

	while (!ft_is_empty(q))
	{
		node = ft_dequeue(q);
		if (ft_is_on_border(node->x, node->y, map) && map->p_map[node->x][node->y] == '0')
		{
			ft_errors_map("Les bords de la carte ne sont pas entourés de 1");
			free(node);
			ft_free_visited(&visited, map->c_collumns);
			return ;
		}
		ft_verify_new_pos(node, map, q, visited);
		free(node);
	}
	ft_free_visited(&visited, map->c_collumns);
}

// Fonction principale du BFS
void	ft_bfs(t_map *map, t_node *start, t_node *goal)
{
	t_queue		q;
	bool		**visited;

	ft_initialize_bfs(map, start, &q, &visited);
	ft_perform_bfs(map, goal, &q, visited);
}
