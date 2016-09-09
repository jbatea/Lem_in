/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playturn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 13:00:58 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:40:01 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_outofstart(t_info *info, t_room *room, char **str)
{
	t_room	*tmp;

	tmp = ft_nextroom(info, room);
	if (tmp)
	{
		tmp->ant = info->curant;
		if (info->curant <= info->nbant)
		{
			ft_printmove(info->curant, tmp, str);
			info->curant = info->curant + 1;
		}
	}
}

void		ft_applymove(t_info *info, t_room *room, char **str)
{
	t_room	*tmp;

	tmp = ft_nextroom(info, room);
	if (tmp)
	{
		if (tmp->info && !ft_strcmp(tmp->info, "end"))
			tmp->ant = tmp->ant + 1;
		else
			tmp->ant = room->ant;
		ft_printmove(room->ant, tmp, str);
		room->ant = 0;
	}
}

void		ft_moveant(t_info *info, int num, char **str)
{
	t_room	*tmp;

	tmp = ft_antptr(info, num);
	if (tmp)
		ft_applymove(info, tmp, str);
	else
		ft_outofstart(info, ft_roomptr(info, ft_inum(info, "start")), str);
}

void		ft_playturn(t_info *info)
{
	int		i;
	char	*str;

	i = 1;
	str = NULL;
	while (i < (info->nbant + 1))
	{
		ft_moveant(info, i, &str);
		i++;
	}
	ft_normstr(str);
}
