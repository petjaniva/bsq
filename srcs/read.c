/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 10:56:06 by bkandemi          #+#    #+#             */
/*   Updated: 2021/06/16 13:45:03 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_list	*create_elem(char *data)
{
	t_list *some_data;

	some_data = (t_list *)malloc(sizeof(some_data));
	if (some_data != NULL)
	{
		some_data->data = data;
		some_data->next = NULL;
	}
	return (some_data);
}

void	list_push_back(t_list **begin_list, char *data)
{
	t_list *element;
	t_list *current;

	element = create_elem(data);
	if (*begin_list == NULL)
	{
		*begin_list = element;
	}
	else
	{
		current = *begin_list;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = element;
	}
}

t_list	*buffer_read(int fd)
{
	char	buffer[BUF_SIZE];
	ssize_t	len;
	t_list	*buffer_head;
	char	*str;
	int		i;

	buffer_head = NULL;
	while ((len = read(fd, buffer, sizeof(buffer))) > 0)
	{
		str = (char *)malloc(sizeof(str) * (len + 1));
		i = 0;
		while (i < len)
		{
			str[i] = buffer[i];
			i++;
		}
		str[i] = '\0';
		list_push_back(&buffer_head, str);
	}
	return (buffer_head);
}
