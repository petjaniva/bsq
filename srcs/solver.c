/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 04:43:07 by pniva             #+#    #+#             */
/*   Updated: 2021/06/16 09:31:18 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	solver(int **matrix, t_map *map, int result[3])
{
	int **findermat;
	int i;
	int j;

	i = -1;
	while (++i < 3)
	{
		result[i] = 0;
	}
	findermat = matrix_mem(map->lines, map->width);
	fillfinder(matrix, findermat, map);
	i = -1;
	while (++i < map->lines)
	{
		j = -1;
		while (++j < map->width)
		{
			if (findermat[i][j] > result[0])
			{
				result[0] = findermat[i][j];
				result[1] = i;
				result[2] = j;
			}
		}
	}
}

int		min(int i, int j, int k)
{
	int min;

	min = i;
	if (j < min)
		min = j;
	if (k < min)
		min = k;
	return (min);
}

void	fillfinder(int **matrix, int **findermat, t_map *map)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < map->lines)
		findermat[i][0] = matrix[i][0];
	while (++j < map->width)
		findermat[0][j] = matrix[0][j];
	i = 1;
	while (i < map->lines)
	{
		j = 1;
		while (j < map->width)
		{
			if (matrix[i][j] == 1)
				findermat[i][j] = (min(findermat[i][j - 1],
				findermat[i - 1][j], findermat[i - 1][j - 1])) + 1;
			else
				findermat[i][j] = matrix[i][j];
			j++;
		}
		i++;
	}
}
