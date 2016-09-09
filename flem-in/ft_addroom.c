/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addroom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:03:13 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/04 15:49:14 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_addroom(t_info *info, char *name, char *str)
{
	t_room	*tmp;
	t_room	*new;

	tmp = info->room;
	new = ft_roominit();
	new->name = ft_strdup(name);
	new->info = ft_strdup(str);
	if (new)
	{
		if (!(info->room))
			info->room = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			new->num = tmp->num + 1;
			tmp->next = new;
		}
	}
	ft_strdel(&name);
}
