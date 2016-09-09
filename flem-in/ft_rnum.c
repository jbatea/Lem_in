/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/04 16:02:03 by jbateau           #+#    #+#             */
/*   Updated: 2016/06/04 16:02:11 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_rnum(t_info *info, char *name)
{
	t_room	*tmp;

	tmp = info->room;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (tmp->num);
		tmp = tmp->next;
	}
	return (-1);
}
