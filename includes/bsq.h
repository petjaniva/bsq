/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pniva <pniva@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:48:28 by bkandemi          #+#    #+#             */
/*   Updated: 2021/06/16 17:37:00 by pniva            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUF_SIZE 1000

typedef struct			s_list
{
	struct s_list		*next;
	char				*data;
}						t_list;

typedef struct			s_map
{
	int					lines;
	int					width;
	int					header;
	char				*first;
}						t_map;

t_list					*create_elem(char *data);
void					list_push_back(t_list **begin_list, char *data);
t_list					*buffer_read(int fd);
void					find_size(t_list *buffer, t_map *map);
void					first_line(t_list *buffer, t_map *map);
int						**create_map(t_list *buffer, t_map *map);
void					map_to_int(char *str, int **matrix, t_map *map);
int						**matrix_mem(int rows, int cols);
void					solver(int **matrix, t_map *map, int result[3]);
void					filler(int **matrix, int result[3]);
void					printer(int **matrix, t_map *map);
void					ft_putchar(char c);
void					ft_putstr(char *str);
int						ft_atoi(char *str);
int						is_map_valid_1(t_map *map);
int						ft_str_is_numeric(char *str);
int						min(int i, int j, int k);
void					fillfinder(int **matrix, int **findermat, t_map *map);
int						is_map_valid_2(t_list *buffer, t_map *map);
char					*ft_strcpy(char *dest, char *src);
int						character_check(t_list *buf, t_map *map);
void					ft_putstrerr(char *str);
void					ft_putcharerr(char c);

#endif
