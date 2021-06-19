/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:55:14 by bkandemi          #+#    #+#             */
/*   Updated: 2021/06/16 16:47:11 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		find_size(t_list *buffer, t_map *map)
{
	int		i;

	map->lines = 0;
	map->width = 0;
	map->header = 0;
	while (buffer != NULL)
	{
		i = 0;
		while (buffer->data[i] != '\0')
		{
			if (buffer->data[i] == '\n')
				map->lines++;
			else if (map->lines == 1)
				map->width++;
			else if (map->lines == 0)
				map->header++;
			i++;
		}
		buffer = buffer->next;
	}
	map->lines--;
}

void		first_line(t_list *buffer, t_map *map)
{
	int		i;
	int		j;

	map->first = (char *)malloc(sizeof(char) * (map->header + 1));
	i = 0;
	while (buffer != NULL)
	{
		j = 0;
		while (buffer->data[j] != '\0')
		{
			if (buffer->data[j] == '\n')
			{
				map->first[i] = '\0';
				return ;
			}
			map->first[i++] = buffer->data[j++];
		}
		buffer = buffer->next;
	}
}

int			is_map_valid_1(t_map *map)
{
	char	*copy;

	copy = (char *)(malloc(sizeof(char) * map->header));
	if (map->header < 4)
	{
		ft_putstrerr("map error\n");
		return (1);
	}
	if (map->lines < 0 || map->width < 0)
	{
		ft_putstrerr("map error\n");
		return (1);
	}
	ft_strcpy(copy, map->first);
	copy[map->header - 3] = '\0';
	if (ft_str_is_numeric(copy) != 1 || ft_atoi(copy) != map->lines)
	{
		ft_putstrerr("map error\n");
		return (1);
	}
	return (0);
}

int			is_map_valid_2(t_list *buffer, t_map *map)
{
	int		i;
	int		width;
	int		line;

	width = 0;
	line = 0;
	while (buffer != NULL)
	{
		i = -1;
		while (buffer->data[++i] != '\0')
		{
			if (buffer->data[i] == '\n')
			{
				if (line > 0)
					if (width != map->width)
						return (1);
				width = 0;
				line++;
			}
			else if (line > 0)
				width++;
		}
		buffer = buffer->next;
	}
	return (0);
}

int			character_check(t_list *buf, t_map *map)
{
	int		i;
	int		line;

	line = 0;
	while (buf != NULL)
	{
		i = 0;
		while (buf->data[i] != '\0')
		{
			if (buf->data[i] == '\n')
				line++;
			else if (buf->data[i] != map->first[map->header - 3]
			&& buf->data[i] != map->first[map->header - 2]
			&& line != 0 && buf->data[i] != '\n')
			{
				ft_putstrerr("map error\n");
				return (1);
			}
			i++;
		}
		buf = buf->next;
	}
	return (0);
}
