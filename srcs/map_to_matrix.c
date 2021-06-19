/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 05:18:23 by bkandemi          #+#    #+#             */
/*   Updated: 2021/06/16 09:38:21 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	g_line;
int	g_wid;

int		**matrix_mem(int rows, int cols)
{
	int i;
	int **matrix;

	matrix = (int **)malloc(sizeof(int *) * rows);
	i = 0;
	while (i < rows)
	{
		matrix[i] = (int *)malloc(sizeof(int) * cols);
		i++;
	}
	return (matrix);
}

void	map_to_int(char *str, int **matrix, t_map *map)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			g_line++;
			g_wid = 0;
		}
		else
		{
			if (g_line > 0)
			{
				matrix[g_line - 1][g_wid] =
				(str[i] == map->first[map->header - 3] ? (1) : (0));
			}
			g_wid++;
		}
		i++;
	}
}

int		**create_map(t_list *buf, t_map *map)
{
	int **matrix;

	matrix = matrix_mem(map->lines, map->width);
	g_line = 0;
	g_wid = 0;
	while (buf != NULL)
	{
		map_to_int(buf->data, matrix, map);
		buf = buf->next;
	}
	return (matrix);
}
