/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:34:55 by shmoreno          #+#    #+#             */
/*   Updated: 2024/07/28 19:28:40 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Function that adds an element to the queue
// If the queue is full, display an error message
void	ft_enqueue(t_queue *q, int x, int y)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	ft_malloc_error(new_node);
	new_node->x = x;
	new_node->y = y;
	if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
	{
		ft_printf("Error: queue is full\n");
		free(new_node);
		return ;
	}
	q->nodes[q->rear] = new_node;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

// Function that removes an element from the queue
// If the queue is empty, display an error message
t_node	*ft_dequeue(t_queue *q)
{
	t_node	*node;

	if (q->front == q->rear)
	{
		ft_printf("Error: queue is empty\n");
		exit(EXIT_FAILURE);
	}
	node = q->nodes[q->front];
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return (node);
}

// Function that checks if the queue is empty
bool	ft_is_empty(t_queue *q)
{
	return (q->front == q->rear);
}

// Function that finds the possible direction for the next movement
void	ft_direction(t_node node, int i, int *n_x, int *n_y)
{
	int	direction_x[4];
	int	direction_y[4];

	direction_x[0] = -1;
	direction_x[1] = 1;
	direction_x[2] = 0;
	direction_x[3] = 0;
	direction_y[0] = 0;
	direction_y[1] = 0;
	direction_y[2] = -1;
	direction_y[3] = 1;
	*n_x = node.x + direction_x[i];
	*n_y = node.y + direction_y[i];
}

void	ft_visited_init(t_map *map, bool ***visited)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	*visited = (bool **)malloc(sizeof(bool *) * map->c_collumns);
	if (!(*visited))
		return ;
	while (i < map->c_collumns)
	{
		(*visited)[i] = (bool *)malloc(sizeof(bool) * map->c_lines);
		if (!(*visited)[i])
		{
			perror("Error");
			ft_free_visited(visited, i);
			exit(EXIT_FAILURE);
		}
		while (j < map->c_lines)
		{
			(*visited)[i][j] = false;
			j++;
		}
		i++;
		j = 0;
	}
}
