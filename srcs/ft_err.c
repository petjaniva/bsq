/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkandemi <bkandemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:45:08 by pniva             #+#    #+#             */
/*   Updated: 2021/06/16 18:05:21 by bkandemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putcharerr(char c)
{
	write(2, &c, 1);
}

void	ft_putstrerr(char *str)
{
	while (*str != '\0')
	{
		ft_putcharerr(*str++);
	}
	return ;
}
