/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 08:13:47 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/30 09:00:01 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_start(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->info && !ft_strcmp("start", tmp->info))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_end(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->info && !ft_strcmp("end", tmp->info))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			ft_checkinfo(t_info *info)
{
	if (!ft_start(info) || !ft_end(info))
		return (0);
	return (1);
}
