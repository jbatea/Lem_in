/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 12:08:15 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:31:06 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_antison(t_info *info)
{
	t_room	*ptr;

	ptr = ft_roomptr(info, ft_inum(info, "end"));
	if (ptr->ant == info->nbant)
		return (1);
	return (0);
}

int			ft_resolve(t_info *info)
{
	while (!ft_antison(info))
	{
		ft_playturn(info);
		ft_putchar('\n');
	}
	return (1);
}
