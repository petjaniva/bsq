/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 18:09:09 by bkandemi          #+#    #+#             */
/*   Updated: 2021/06/16 16:47:56 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			read_solve_print(int fd)
{
	t_list	*buffer;
	t_map	map;
	int		**matrix;
	int		result[3];

	buffer = buffer_read(fd);
	find_size(buffer, &map);
	first_line(buffer, &map);
	matrix = create_map(buffer, &map);
	if ((character_check(buffer, &map)) == 1)
		return (1);
	if (is_map_valid_1(&map) == 1)
		return (1);
	if (is_map_valid_2(buffer, &map) == 1)
	{
		ft_putstrerr("map error\n");
		return (1);
	}
	solver(matrix, &map, result);
	filler(matrix, result);
	printer(matrix, &map);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		n;

	if (argc == 1)
	{
		read_solve_print(0);
		return (0);
	}
	n = 0;
	while (++n < argc)
	{
		fd = open(argv[n], O_RDONLY);
		read_solve_print(fd);
		if (argc > 2 && n < argc - 1)
			ft_putchar('\n');
	}
	return (0);
}
