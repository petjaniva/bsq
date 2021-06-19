/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:33:07 by pniva             #+#    #+#             */
/*   Updated: 2021/06/16 13:43:43 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	filler(int **matrix, int result[3])
{
	int i;
	int j;

	i = 0;
	while (i < result[0])
	{
		j = 0;
		while (j < result[0])
		{
			matrix[result[1] - i][result[2] - j] = 9;
			j++;
		}
		i++;
	}
}

void	printer(int **matrix, t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->lines)
	{
		j = 0;
		while (j < map->width)
		{
			if (matrix[i][j] == 1)
				ft_putchar(map->first[map->header - 3]);
			else if (matrix[i][j] == 0)
				ft_putchar(map->first[map->header - 2]);
			else if (matrix[i][j] == 9)
				ft_putchar(map->first[map->header - 1]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
