/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:48:25 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/07 12:05:16 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_nbantinit(t_info *info)
{
	t_room	*tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->info && !ft_strcmp(tmp->info, "start"))
		{
			tmp->ant = info->nbant;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			ft_weightinit(t_info *info)
{
	t_room	*tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->info && !ft_strcmp(tmp->info, "end"))
		{
			tmp->weight = 0;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		ft_startinit(t_info *info, char *map)
{
	ft_nbantinit(info);
	ft_weightinit(info);
	ft_addweight(info, map);
}
