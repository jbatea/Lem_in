/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addweight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:38:05 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/10 11:30:15 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_roomnext(t_info *info, int i)
{
	t_adjnode	*tmp;
	t_room		*ptr;
	int			weight;

	ptr = NULL;
	weight = ft_roomptr(info, i)->weight;
	tmp = info->array[i].head;
	while (tmp)
	{
		ptr = ft_roomptr(info, tmp->to);
		if (tmp->to != ft_inum(info, "start"))
		{
			if (ptr->weight == -1 || ptr->weight > weight + 1)
			{
				ptr->weight = weight + 1;
				ft_addfile(info, tmp->to);
			}
		}
		else
			ptr->weight = 0;
		tmp = tmp->next;
	}
}

void			ft_addweight(t_info *info, char *map)
{
	t_file		*file;

	ft_roomnext(info, ft_inum(info, "end"));
	file = info->first;
	while (file)
	{
		ft_roomnext(info, file->num);
		ft_delfile(info);
		file = info->first;
	}
	free(file);
	if (ft_roomptr(info, ft_inum(info, "start"))->weight)
	{
		ft_strdel(&map);
		ft_exit(info, -1);
	}
}
