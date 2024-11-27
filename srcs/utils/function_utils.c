/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmoreno <shmoreno@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:25:12 by shmoreno          #+#    #+#             */
/*   Updated: 2024/11/25 11:35:47 by shmoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strlen_find(char *str, char c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (c == 'N')
		{
			if (i + 1 < ft_strlen(str) && str[i] == '.'
				&& str[i + 1] == '/')
				return (i);
			else if (ft_isdigit(str[i]))
				return (i);
		}
		else if (i + 1 < ft_strlen(str) && str[i] == c
			&& str[i + 1] == '/' && c == '.')
			return (i);
		i++;
	}
	return (i);
}

// Count the number of elements in a 2D array
int	ft_count_index(char **input)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i] != NULL)
	{
		count++;
		i++;
	}
	return (count);
}
