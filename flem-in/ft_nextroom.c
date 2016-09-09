/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextroom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 16:07:51 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:30:26 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*ft_nextroom(t_info *info, t_room *room)
{
	t_room		*r;
	t_adjnode	*tmp;
	int			ntmp;
	int			weight;

	ntmp = -1;
	weight = -1;
	r = NULL;
	tmp = info->array[room->num].head;
	while (tmp)
	{
		r = ft_roomptr(info, tmp->to);
		if ((!(r->ant) && r->weight != -1) || (r->num == ft_inum(info, "end")))
		{
			if (weight == -1 || r->weight < weight)
			{
				ntmp = r->num;
				weight = r->weight;
			}
		}
		tmp = tmp->next;
	}
	if (ntmp != -1)
		return (ft_roomptr(info, ntmp));
	return (NULL);
}
